class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0 ;
        int max_lenght = 0; 

        for(int right = 0 ; right < nums.size() ; right++){
            //checking if the element  = 1 
            if(nums[right] == 1){
                max_lenght = max(max_lenght ,  right - left +1 );
            }

            //if its 0 
            else {
                left = right+1;
            }
        }
        return max_lenght ; 
    }
};