#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int fff(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        int minLength = INT_MAX;
        int s1_length = s1.size(), s2_length = s2.size(), s3_length = s3.size();
        for(int i = 0; i < l1.size(); i++){

            int s = l1[i];

            auto it1 = lower_bound(l2.begin(), l2.end(), s + s1_length);
            if(it1 == l2.end()) continue;;

            int middle = *it1;
            //cout << "middle: " << middle << endl;

            auto it2 = lower_bound(l3.begin(), l3.end(), middle + s2_length);

            if(it2 == l3.end()) continue;

            int last = *it2;

            //cout << "s: " << s << "middle: " << middle << "last: " << last << endl;

            minLength = min(minLength, last + s3_length - s);
        }

        //cout << "hiiiii" << endl;
        //if(minLength != INT_MAX) cout << "mini: " << minLength << endl;
        return minLength == INT_MAX ? -1 : minLength;

    }

    int ffe(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        if(!s3.empty()) return -1;
        int minLength = INT_MAX;
        int s1_length = s1.size(), s2_length = s2.size();
        for(int i = 0; i < l1.size(); i++){
            int s = l1[i];

            auto it1 = lower_bound(l2.begin(), l2.end(), s + s1_length);
            if(it1 == l2.end()) continue;

            int middle = *it1;
            minLength = min(minLength, middle + s2_length - s);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

    int fef(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        if(!s2.empty()) return -1;
        int minLength = INT_MAX;
        int s1_length = s1.size(), s3_length = s3.size();
        for(int i = 0; i < l1.size(); i++){
            int s = l1[i];

            auto it2 = lower_bound(l3.begin(), l3.end(), s + s1_length);

            if(it2 == l3.end()) continue;

            int last = *it2;
            minLength = min(minLength, last + s3_length - s);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

    int fee(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        if(!s2.empty() || !s3.empty()) return -1;
        return !l1.empty() ? s1.size() : -1;
    }

    int eff(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        if(!s1.empty()) return -1;
        int minLength = INT_MAX;
        int s3_length = s3.size(), s2_length = s2.size();
        for(int i = 0; i < l2.size(); i++){
            int s = l2[i];

            auto it1 = lower_bound(l3.begin(), l3.end(), s + s2_length);
            if(it1 == l3.end()) continue;

            int middle = *it1;
            minLength = min(minLength, middle + s3_length - s);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

    int efe(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        if(!s1.empty() || !s3.empty()) return -1;
        return !l2.empty() ? s2.size() : -1;
    }
    int eef(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        if(!s1.empty() || !s2.empty()) return -1;
        return !l3.empty() ? s3.size() : -1;
    }
    int eee(vector<int>& l1, vector<int>& l2, vector<int>& l3, string& s1, string& s2, string& s3){
        return -1;
    }

    void findOccurences(vector<int>& l, string& sub, string& s){
        // give the starting position from where to find
        int s_length = sub.size();
        size_t idx = s.find(sub, 0);
        while(idx != string :: npos){
            l.push_back(idx);
            idx = s.find(sub, idx+1);
        }

        // for(int i : l) cout << i << " ";
        // cout << endl;
    }
public:
    int shortestMatchingSubstring(string s, string p) {
        // the minimum length of substring used for matching with p is 0 and the maximum length is s.size()
        int sn = s.size(), pn = p.size();

        // we know that the string has exactly 2 '*' which can match with anything 
        // so in the window of length window we need to check whether we can find
        // str 1  -> string before first '*'
        // str 2 -> string between first and second '*'
        // str 3 -> string after second '*'

        // find the position of star 1 and 2
        size_t pos1 = p.find('*', 0);
        size_t pos2 = p.find('*', pos1+1);
        //cout << "pos1: " << pos1 << " pos2: " << pos2 << endl;
        
        // substring function takes 2 parameters start point and length of substring
        string s1, s2, s3;
        if(pos1 > 0) s1 = p.substr(0, pos1);
        if(pos2 - pos1 > 1) s2 = p.substr(pos1+1, pos2 - pos1 - 1);
        if(pos2 < pn - 1) s3 = p.substr(pos2 + 1);


        // initial base case - when p has only **
        if(s1.empty() && s2.empty() && s3.empty()) return 0;

        //cout << "s1: " << s1 << " s2: " << s2 << " s3: " << s3 << endl;

        // now store all the starting positions of the all the substrings s1, s2 and s3
        vector<int> l1, l2, l3;

        if(!s1.empty()){
            findOccurences(l1, s1, s);
        }

        if(!s2.empty()){
            findOccurences(l2, s2, s);
        }

        if(!s3.empty()){
            findOccurences(l3, s3, s);
        }


        
        int minLength = -1;
        if(!l1.empty() && !l2.empty() && !l3.empty()){
            //cout << "hello" << endl;
            
            minLength = fff(l1, l2, l3, s1, s2, s3);
        } 
        else if(!l1.empty() && !l2.empty() && l3.empty()){
            
            minLength = ffe(l1, l2, l3, s1, s2, s3);
        } 
        else if(!l1.empty() && l2.empty() && !l3.empty()){
            
            minLength = fef(l1, l2, l3, s1, s2, s3);
        } 
        else if(!l1.empty() && l2.empty() && l3.empty()){
            
            minLength = fee(l1, l2, l3, s1, s2, s3);
        } 
        else if(l1.empty() && !l2.empty() && !l3.empty()){
            
            minLength = eff(l1, l2, l3, s1, s2, s3);
        } 
        else if(l1.empty() && !l2.empty() && l3.empty()){
            
            minLength = efe(l1, l2, l3, s1, s2, s3);
        } 
        else if(l1.empty() && l2.empty() && !l3.empty()){
            
            minLength = eef(l1, l2, l3, s1, s2, s3);
        } 
        else if(l1.empty() && l2.empty() && l3.empty()){
            
            minLength = eee(l1, l2, l3, s1, s2, s3);
        } 

        return minLength;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    string s = "dahtpsnutgopcsrqknpjkvoudkklusqnptahoijdiikmwqkyaeplxtzwinmqkyikoiejknfyyrtpjcavtiwkqvsbzuuetqbsiijpihbmthmobixijrbdpcdvaitvbahezfhmklbozpifhsxnfyppnqhaygczmumnxcforxhbmbhmokgwyinqoclpuueovxgvyucrupyawjrzlxefnvedpytagufkfczsrnmgcgagytdfaxxlpvlaclpgclxnanrdfpnzgufmecxxquypdosixnvsvyfykrrjufgpizmbhkzycpyypwpvllordzxbrpvrviagzwsrzhfjdndbyzziowaetucpsvijpknvtbfvhyhnxnzicwmoyemkrdpccfaleezlzqbccogxkbfcbqncfqhgdqwruwtgldhsusabfffszovblkpjlqgwemsqtwlofizjafmxtymmsrqttmnnntvzznqhoavwpsscxcxvmerflrdvchlxbnrfqfvjrkmxviaqhekgzfdcfqvekbciyxjtpfnvbnrwdkyknxfxtxvlcbqdytccdxjmmjxnbflpfgvfzpwoiwcbospkwhuzutuqiuynjvtcdtgwwtybasbboomogtrciaczguppfwzxqeinucqblsbarmpisfvtaoywrsaygmsyacjwlasjmthqxuxkxgjavervexvabrrztdiyyzqjejyfqrfjwpefusyincxxlwweeqybavdxznsoardbglswfczlbiexewhrcdgapkcxlsnqelimxexudgmhlulobbiikljlkpdktublr", 
    p = "lavdwgkqsnslwqgxomtssrzpvixbrxczfdiuzxnaemardtxvpwnwermrykdruvjohlcyrgygtbdpgkpuwnxnttbzpyivmpzudplxviyvkufzoaashwdwgpprckqzfbyvbirpihpfyopnuussdpoxlkysxernufrbpkzshzldnjfitgmiibopljzzjxrstnkvdcincvcywtnx*mtzzcxwmzkjbtqnotljmzxdqzarevdcyonpzizphxlqcijbuaqkffnaocxnhtggrzdhequssgwtqioiflreoljmlhidlbmvigyyqmxamtwelrisysmxbcosoebzctotkbnnvdxnrcffnynwrjwbyglyywjzirzmesvzgmijxjmidchdggxvrrmjcylhojmrljptbhlbfasnrxhrkdxqxdygacihdd*vdgtjfotrjafgfkthfuckwbmsoipw";
    cout << sol.shortestMatchingSubstring(s, p) << endl;
    
    return 0;
}