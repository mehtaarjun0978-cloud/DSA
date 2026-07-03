class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //will tell us the number of time we have visited the sum-j 
        map<int , int > mpp;
        mpp[0] = 1;

        int n = nums.size();

        int p_sum = 0 , cnt =0 ;

        for(int j = 0 ; j<n ; j++){
            p_sum += nums[j];
            //revoval means that x-k value x->total psum till j & k->required subarray
            int removal =  p_sum - k;
            cnt += mpp[removal];
            mpp[p_sum] += 1;
        }

        return cnt;
    }
};