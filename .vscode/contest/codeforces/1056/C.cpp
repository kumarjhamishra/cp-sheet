#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

//#define pb push_back

void solve(){
    /*
    solution:
    let's make an array b: bi = 0 -> cape position in left for ith position
                           bi = 1 -> cape position in right for ith position

    number of wizards visible from position i is the sum of:
    1) left position capes bj = 0 for j <= i
    2) right position capes bj = 1 for j >= i
    counting (1-bj) because counting total left position capes in left to i
    ai = (∑j=1toi (1-bj)) + (∑j=iton bj)

    ai = (∑j=1toi (1-bj)) + (∑j=iton bj) ----------> 1
    ai-1 = (∑j=1toi-1 (1-bj)) + (∑j=i-1ton bj) ----> 2

    1-2 gives:
    ai - ai-1 = (1-bi) - bi-1
    rearrangment gives bi = 1 - bi-1 - (ai - ai-1)

    which shows that just by deciding b1 the whole array b can be formed
    and there are only 2 possible values for b1 which is 0 and 1


    now some checks after forming b for it's validation:
    1) all bi should be either 0 and 1
    2) validating a1
        from eqn-1 a1 can be written as:
        a1 = (1-b1) + (b1+b2+...+bn)
        a1 = 1 + (b2+...+bn)
    */

    int n;
    cin >> n;

    vi a(n);
    for(auto &i : a) cin >> i;

    int totalArrangements = 0;
    for(int b1 = 0; b1 <= 1; b1++){
        vi b(n);
        b[0] = b1;
        bool isBreaked = false;
        for(int i = 1; i < n; i++){
            b[i] = 1 - b[i-1] - (a[i] - a[i-1]);

            // validation check 1
            if(b[i] != 0 && b[i] != 1){
                isBreaked = true;
                break;
            }
        }
        if(isBreaked) continue;

        // validation check 2
        int cnt = 1 + accumulate(b.begin()+1, b.end(), 0);
        if(cnt == a[0]){
            totalArrangements++;
        }
    }

    cout << totalArrangements << endl;
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