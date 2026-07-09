class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //hasmap to find duplicates 
        unordered_map<char,int> mpp;

        int l =0 ,r = 0 ;
        int ans = 0 ;

        //traverse through the whole string
        for(r = 0 ; r < s.size() ; r++){
            auto it = mpp.find(s[r]);

            //if duplicate is present 
            if( it != mpp.end() && it->second >= l ){
                //duplicate is present and is inside our window
                //move the left pointer to the left of the previous ocuurance of that char
                l = it->second +1 ;
            }

            //if not present in HM then add the element in HM 
            mpp[s[r]] = r;
            
            //updating our max length of sub array 
            ans = max(ans , r-l+1);
        }
        return ans;
    }
};