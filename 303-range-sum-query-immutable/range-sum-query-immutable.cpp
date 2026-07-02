class NumArray {
public:
    // make a vector that stores the prefix_sum of the the refrenced vector
    vector<int> p_nums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        //give the p_num the same size as that of nums 
        p_nums.resize(n);

        p_nums[0] = nums[0];

        for(int i = 1 ; i<n ; i++){
            p_nums[i] = p_nums[i-1] + nums[i];
        }   
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return p_nums[right] ;

        return p_nums[right] - p_nums[left -1 ];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */