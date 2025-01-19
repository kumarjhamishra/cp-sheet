#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class Info>

class SegmentTree{
    public:
    int n;
    vector<Info> segTree;

    SegmentTree(int n_, Info default_value = Info()){
        init(n_, default_value);
    }

    template <class T>
    SegmentTree(vector<T> values){
        init(values);
    }

    void init(int n_, Info default_value = Info()){
        init(vector<Info>(n_, default_value));
    }

    template <class T>
    void init(vector<T> values){
        n = values.size();
        int tree_size = 4*n;
        segTree.assign(tree_size, Info());
        build(0, 0, n-1, values);
    }

    Info queryRange(int qs, int qe){
        return queryRange(0, 0, n-1, qs, qe);
    }

    void update(int idx, const Info& new_value){
        update(0, 0, n-1, idx, new_value);
    }

    Info queryPoint(int idx){
        return queryPoint(0, 0, n-1, idx);
    }
    

    void build(int seg_i, int l, int r, const vector<Info> &values){
        if(l == r){
            segTree[seg_i] = values[l];
            return ;
        }

        int mid = l + (r-l)/2;
        build(2*seg_i+1, l, mid, values);
        build(2*seg_i+2, mid+1, r, values);
        segTree[seg_i] = segTree[2*seg_i+1] + segTree[2*seg_i+2];
        return ;
    }

    Info queryRange(int seg_i, int l, int r, int qs, int qe){
        // no overlap
        if(r < qs || qe < l) return Info();

        // total overlap
        if(l == qs && r == qe) return segTree[seg_i];

        // partial overlap
        int mid = l + (r-l)/2;
        return queryRange(2*seg_i+1, l, mid, qs, qe) + queryRange(2*seg_i+2, mid+1, r, qs, qe);
    }

    void update(int seg_i, int l, int r, int idx, const Info &new_value){
        if(l == r){
            segTree[seg_i] = new_value;
            return ;
        }

        int mid = l + (r-l)/2;
        if(idx <= mid) update(2*seg_i+1, l, mid, idx, new_value);
        else update(2*seg_i+2, mid+1, r, idx, new_value);
        segTree[seg_i] = segTree[2*seg_i+1] + segTree[2*seg_i+2];
        return ;
    }

    Info queryPoint(int seg_i, int l, int r, int idx){
        if(l == r) return segTree[seg_i];

        int mid = l + (r-l)/2;
        if(idx <= mid) return queryPoint(2*seg_i+1, l, mid, idx);
        return queryPoint(2*seg_i+2, mid+1, r, idx);
    }
};

class Info{
    public:
    int min1, min2, max1, max2, ans1, ans2;

    Info() : min1(INT_MAX), min2(INT_MAX), max1(INT_MIN), max2(INT_MIN), ans1(0), ans2(0) {}

    Info(pair<int, int> x) : min1(x.first), min2(x.second), max1(x.first), max2(x.second), ans1(0), ans2(0) {}

    Info operator+(const Info& other) const {
        Info res;
        res.min1 = min(min1, other.min1);
        res.min2 = min(min2, other.min2);
        res.max1 = max(max1, other.max1);
        res.max2 = max(max2, other.max2);
        res.ans1 = max({ans1, other.ans1, other.max1 - min1});
        res.ans2 = max({ans2, other.ans2, max2 - other.min2});
        return res;
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> sweater(n);
    vector<Info> t(n);

    for(int i = 0; i < n; i++){
        cin>>sweater[i];
        t[i] = Info({sweater[i]-i, sweater[i]+i-n+1});
    }

    SegmentTree<Info> st(t);
    auto query = [&](){
        return max(st.segTree[0].ans1, st.segTree[0].ans2);
    };

    cout<<query()<<endl;

    for(int i = 0; i < q; i++){
        int p, x;
        cin>>p>>x;
        p--; // for 0 based indexing
        t[p] = Info({x-p, x+p-n+1});
        st.update(p, t[p]);
        cout<<query()<<endl;
    }
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}