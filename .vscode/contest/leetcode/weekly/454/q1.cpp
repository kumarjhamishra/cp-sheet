#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string generateTag(string caption)
    {
        string tag = "#";
        int tagSize = 1, n = caption.size();
        bool first = true, breaked = false;

        for(int i = 0; i < n; ){
            if(caption[i] == ' '){
                i++;
            }
            else if(first){
                char lower = tolower(caption[i]);
                tag.push_back(lower);
                tagSize++;
                if(tagSize == 100) break;

                int j = i+1;
                while(j < n && caption[j] != ' '){
                    char lower = tolower(caption[j]);
                    tag.push_back(lower);
                    tagSize++;
                    if(tagSize == 100){
                        breaked = true;
                        break;
                    }
                    j++;
                }
                if(breaked) break;
                i = j+1;
                first = false;
            }
            else{
                char upper = toupper(caption[i]);
                tag.push_back(upper);
                tagSize++;
                if(tagSize == 100) break;
                int j = i+1;
                while(j < n && caption[j] != ' '){
                    char lower = tolower(caption[j]);
                    tag.push_back(lower);
                    tagSize++;
                    if(tagSize == 100){
                        breaked = true;
                        break;
                    }
                    j++;
                }
                if(breaked) break;
                i = j+1;
            }
        }

        //cout << "tag size: " << tag.size() << endl;
        cout << tag << endl;
        return tag;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string caption = " fPysaRtLQLiMKVvRhMkkDLNedQKffPnCjbITBTOVhoVjiKbfSawvpisDaNzXJctQkn";
    cout << sol.generateTag(caption);


    return 0;
}