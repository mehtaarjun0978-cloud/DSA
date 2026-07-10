class Solution {
public:

    int atmost(vector<int> & nums , int k ){
        int left = 0 ;
        //we donk know the exact counts of numbers hence using hash map 
        unordered_map <int, int> freq;
        int ans = 0 ;

        //traverse through the whole vector
        for(int right = 0 ; right < nums.size() ; right++){
            // update the freq 
            freq[nums[right]]++;

            while(freq.size() > k ){
                // we will perform shrinking 
                freq[nums[left]]--;

                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }

                left++;
            }

            if(freq.size() <= k){
                ans += right - left +1 ;           // no of sub arrays 
            }
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums ,k) - atmost(nums,k-1) ;       
    }
};