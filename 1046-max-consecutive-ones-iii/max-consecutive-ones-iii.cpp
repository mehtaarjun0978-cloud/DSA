class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 ; 
        int max_length = 0 ;
        int zero_count = 0 ;

        //iterate through the whole vector 
        for(int right = 0 ; right < nums.size() ; right++){
            //keep the window sliding and keep the count of zeros with each window 
            if (nums[right] == 0 ){
                zero_count ++;
            }

            while(zero_count > k){
                //keep moving left pointer untill it is equals to zero 
                if(nums[left] == 0){
                    zero_count--;
                    left++;
                }
                
                else{
                    left++;
                }
            }

            max_length = max(max_length , right - left + 1);
        }
        return max_length;

    }
};