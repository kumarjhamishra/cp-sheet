class NumArray {
public:
    int n;
    vector<int> segTree, nums;
    //vector<int> lazy; // for update function

    void build(int seg_i, int l, int r, vector<int> &nums){
        // base case
        if(l == r){
            segTree[seg_i] = nums[l];
            return ;
        }

        int mid = l + (r-l)/2;
        build(2*seg_i+1, l, mid, nums);
        build(2*seg_i+2, mid+1, r, nums);
        segTree[seg_i] = segTree[2*seg_i+1] + segTree[2*seg_i+2];
        return ;
    }

    void updateSegTree(int seg_i, int l, int r, int index, int val){
        // base case
        if(l == r){
            segTree[seg_i] = val;
            return ;
        }

        int mid = l + (r-l)/2;
        if(mid <= index) updateSegTree(2*seg_i+1, l, mid, index, val);
        else updateSegTree(2*seg_i+2, mid+1, r, index, val);

        segTree[seg_i] = segTree[2*seg_i+1] + segTree[2*seg_i+2];
        return ;
    }

    int querySegmentTree(int seg_i, int s, int e, int qs, int qe){

        // no overlapping
        if(qe < s || e < qs) return 0;

        // total overlapping
        if(qs <= s && e <= qe) return segTree[seg_i];

        int mid = s + (e-s)/2;
        return querySegmentTree(2*seg_i+1, s, mid, qs, qe) + querySegmentTree(2*seg_i+2, mid+1, e, qs, qe);
    }

    NumArray(vector<int>& nums) {
        nums = nums;
        n = nums.size();
        segTree.resize(4*n);
        //lazy.resize(4*n, 0); // the lazy arr is need to be initialised with value 0
        build(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateSegTree(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return querySegmentTree(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */