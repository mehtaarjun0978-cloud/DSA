class Solution {
public:
    int characterReplacement(string s, int k) {
        //we will use hashmap to identify the count of coming characters
        unordered_map<char, int> freq;
        int max_length = 0 ;
        int left = 0 ;
        int max_freq = 0 ;

        for(int right = 0 ; right < s.size() ; right++){
            freq[s[right]]++;

            max_freq  = max(max_freq , freq[s[right]]); 

            //no of replaceplacement we needed is window_lenght - max_freq

            //if this number of replacement is greater than k(no of replacement  we are allowed to do) , then shrink the window_size

            while( (right - left + 1) - max_freq > k){
                    //shrink the window 
                    freq[s[left]]--;
                    left++;
            }

            //if this number of replacement is less than k(no of replacement that we are allowed to do) , then we will  update the window_size 
            max_length = max(max_length , right - left +1);
        }
        return max_length;
    }
};