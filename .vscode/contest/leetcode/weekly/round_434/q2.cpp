#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> usersMention(numberOfUsers, 0);
        int time = 0, toAddInAll = 0;
        priority_queue<p, vector<p>, greater<p>> offlineUsers;
        vector<bool> isOffline(numberOfUsers, false);

        // offline = 0, msg = 1
        // {timeStamp, offline/msg, index}
        vector<vector<int>> sortedEvents;
        int eventSize = events.size();
        for(int i = 0; i < eventSize; i++){
            int timeStamp = stoi(events[i][1]);
            int msg = (events[i][0] == "MESSAGE");
            sortedEvents.push_back({timeStamp, msg, i});
        }

        sort(sortedEvents.begin(), sortedEvents.end());


        for(int i = 0; i < eventSize; i++){
            int index = sortedEvents[i][2];
            //cout << "hello" << endl;
            if(events[index][0] == "MESSAGE"){
                int timeStamp = stoi(events[index][1]);

                // remove all of the users who now can be offline again
                while(!offlineUsers.empty() && offlineUsers.top().first <= timeStamp){
                    p node = offlineUsers.top();
                    int id = node.second;
                    offlineUsers.pop();
                    isOffline[id] = false;
                }

                if(events[index][2] == "ALL") toAddInAll++;
                    
                // mention all online users
                else if(events[index][2] == "HERE"){
                    for(int id = 0; id < numberOfUsers; id++){
                        if(!isOffline[id]) usersMention[id] += 1;
                    }
                }

                else{
                    int idx = 2, _size = events[index][2].size();

                    while(idx < _size){
                        string id;
                        while(idx < _size && events[index][2][idx] != ' '){
                            id.push_back(events[index][2][idx]);
                            idx++;
                        }

                        idx += 3;
                        int _id = stoi(id);
                        usersMention[_id] += 1;
                    }
                }
            }
            else{
                int timeStamp = stoi(events[index][1]);
                int _id = stoi(events[index][2]);

                //after the time timeStamp, now all the time queries will >= timeStamp
                // so remove all those id from offline mode whose time of offline is less than equal to timeStamp
                while(!offlineUsers.empty() && offlineUsers.top().first <= timeStamp){
                    p node = offlineUsers.top();
                    int id = node.second;
                    offlineUsers.pop();
                    isOffline[id] = false;
                }
                
                offlineUsers.push({timeStamp+60, _id});
                isOffline[_id] = true;
            }
        }

        for(int id = 0; id < numberOfUsers; id++){
            usersMention[id] += toAddInAll;
        }

        return usersMention;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        //solve();
    }

    return 0;
}