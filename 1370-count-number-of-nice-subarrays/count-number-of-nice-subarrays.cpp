class Solution {
public:
    int atmost(vector<int>& nums , int k ){
        int left =0 ; 
        int ans = 0;

        for(int right = 0 ; right < nums.size() ; right++){
             if(nums[right] %2){
                k--;              //we found an oodd number
             }

             while(k<0){
                // means we have found more than k odd elements
                if(nums[left] % 2){
                    // means we have found an odd int
                    k++;
                } 
                left++;
             }

              // number of sub array if window = [left , right]  -> right - left +1 
              //means every subarray possible which ends with [right element]
              ans += right-left+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
            return atmost(nums,k) - atmost(nums,k-1);
    }
};