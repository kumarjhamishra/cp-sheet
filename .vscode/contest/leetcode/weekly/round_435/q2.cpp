#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /*
        int f(string& s, int k, char y_dir, char x_dir){
            int dist = 0, maxDist = INT_MIN;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == y_dir || s[i] == x_dir) dist++;
                else if(k > 0){
                    dist++;
                    k--;
                }
                else dist--;
                maxDist = max(maxDist, dist);
            }

            return maxDist;
        }
    */
public:
    int maxDistance(string s, int k)
    {
        /*
        // explore 4 directions -> North-East, North-West, South-East, South-West
        int dist = f(s, k, 'N', 'E');
        dist = max(dist, f(s, k, 'N', 'W'));
        dist = max(dist, f(s, k, 'S', 'E'));
        dist = max(dist, f(s, k, 'S', 'W'));

        return dist;
*/
        

        int x = 0, y = 0, total_x = 0, total_y = 0, dist = 0;
        for (char& dir : s)
        {
            total_x += (dir == 'E') + (dir == 'W');
            total_y += (dir == 'N') + (dir == 'S');

            x += (dir == 'E') - (dir == 'W');
            y += (dir == 'N') - (dir == 'S');

            dist = max(dist, abs(x) + abs(y) + min(total_x - abs(x) + total_y - abs(y), 2 * k));
        }

        return dist;
        

        
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "NSWWEW";
    int k = 3;
    Solution sol;
    cout << sol.maxDistance(s, k) << endl;

    return 0;
}