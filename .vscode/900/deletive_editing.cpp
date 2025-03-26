#include <bits/stdc++.h>
using namespace std;

// deletive_editing.cpp

void solve(){
    string s, t;
    cin >> s >> t;

    // maintain the frequencies of each character in both s and t
    vector<int> freq_s(26, 0), freq_t(26, 0);
    for(char c : s){
        freq_s[c - 'A']++;
    }

    for(char c : t){
        freq_t[c - 'A']++;
    }

    // we need to remove the freq_s[i] - freq_t[i] times each character's first occurence from the s 
    // in order to check whether t can be formed from s or not

    for(int i = 0; i < 26; i++){
        if(freq_s[i] < freq_t[i]){
            cout << "NO" << endl;
            return;
        }
        freq_s[i] -= freq_t[i];
    }


    for(int i = 0; i < s.size(); i++){
        if(freq_s[s[i] - 'A'] > 0){
            freq_s[s[i] - 'A'] -= 1;
            s[i] = '*';
        }
    }

    //cout <<"s: " <<  s << endl;

    int i = 0, j = 0;
    while(i < s.size() && j < t.size()){
        if(s[i] == '*') i++;
        else if(s[i] == t[j]){
            i++;
            j++;
        }
        else{
            cout << "NO" << endl;
            return ;
        }
    }

    if(j != t.size() && i == s.size()){
        cout << "NO" << endl;
        return ;
    }

    cout << "YES" << endl;
    return ;
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