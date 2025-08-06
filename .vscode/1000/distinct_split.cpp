#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vi rightFreq(26, 0), leftFreq(26, 0);
    for(char ch : s) rightFreq[ch - 'a']++;
    rightFreq[s[0] - 'a']--;

    int rightScore = 0;;
    for(int i = 0; i < 26; i++){
        if(rightFreq[i] != 0) rightScore++;
    }
    int leftScore = 1, maxScore = leftScore + rightScore;
    leftFreq[s[0] - 'a']++;
    for(int i = 1; i < n-1; i++){
        char ch = s[i];
        leftFreq[ch - 'a']++;
        if(leftFreq[ch - 'a'] == 1) leftScore++;
        rightFreq[ch - 'a']--;
        if(rightFreq[ch - 'a'] == 0) rightScore--;

        maxScore = max(maxScore, leftScore + rightScore);
    }

    cout << maxScore << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}