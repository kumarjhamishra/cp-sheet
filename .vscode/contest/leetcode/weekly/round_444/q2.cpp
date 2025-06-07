#include <bits/stdc++.h>
using namespace std;

class Packet
{
public:
    int source;
    int destination;
    int timestamp;

    Packet(int source, int destination, int timestamp) : source(source), destination(destination), timestamp(timestamp) {}

    bool operator<(const Packet &other) const
    {
        if (source != other.source)
            return source < other.source;
        if (destination != other.destination)
            return destination < other.destination;
        return timestamp < other.timestamp;
    }
};

class Router
{
private:
    vector<Packet> packets;
    set<Packet> packetSet;
    // to keep track the number of packets with destination with a range of time limit
    unordered_map<int, vector<int>> destinationMap;
    int packetsSize = 0;
    int memoryLimit = 0;

public:
    Router(int memoryLimit)
    {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        // check if this packet is already in the set
        Packet newPacket = Packet(source, destination, timestamp);
        if (packetSet.find(newPacket) != packetSet.end())
        {
            // cout << "hello" << endl;
            // cout << "false" << endl;
            return false;
        }
        // cout << "hello" << endl;
        packets.push_back(newPacket);
        packetsSize += 1;
        packetSet.insert(newPacket);
        destinationMap[destination].push_back(timestamp);
        if (packetsSize > memoryLimit)
        {
            // remove the oldest packet from the set and vector
            Packet oldestPacket = packets[0];
            packets.erase(packets.begin());
            packetSet.erase(oldestPacket);
            // remove this packet from the destination map
            auto &vec = destinationMap[oldestPacket.destination];
            vec.erase(remove(vec.begin(), vec.end(), oldestPacket.timestamp), vec.end());
            if (vec.empty())
            {
                destinationMap.erase(oldestPacket.destination);
            }
            packetsSize -= 1;
        }
        // cout << "true" << endl;
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packetsSize == 0)
        {
            // cout << "empty" << endl;
            return {};
        }

        // remove the oldest packet from the set and vector
        Packet oldestPacket = packets[0];
        packets.erase(packets.begin());
        packetSet.erase(oldestPacket);
        // remove this packet from the destination map
        auto &vec = destinationMap[oldestPacket.destination];
        vec.erase(remove(vec.begin(), vec.end(), oldestPacket.timestamp), vec.end());
        if (vec.empty())
        {
            destinationMap.erase(oldestPacket.destination);
        }
        packetsSize -= 1;

        // cout << oldestPacket.source << " " << oldestPacket.destination << " " << oldestPacket.timestamp << endl;
        return {oldestPacket.source, oldestPacket.destination, oldestPacket.timestamp};
    }

    int getCount(int destination, int startTime, int endTime)
    {
        
        // now we will find the count of packets in the range [startTime, endTime] with binary search 
        if(destinationMap.find(destination) == destinationMap.end()){
            return 0;
        }
        int totalCount = destinationMap[destination].size();

        auto &timestamps = destinationMap[destination];
        // auto lower = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        // auto upper = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        // totalCount = distance(lower, upper);
        int countBeforeStart = 0, countAfterEnd = 0;

        // Count elements less than or equal to startTime - 1
        if (startTime > 0)
        {
            auto beforeStart = upper_bound(timestamps.begin(), timestamps.end(), startTime - 1);
            countBeforeStart = distance(timestamps.begin(), beforeStart);
        }

        // Count elements greater than or equal to endTime + 1
        auto afterEnd = lower_bound(timestamps.begin(), timestamps.end(), endTime + 1);
        countAfterEnd = distance(afterEnd, timestamps.end());

        totalCount -= (countBeforeStart + countAfterEnd);
        return totalCount;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}