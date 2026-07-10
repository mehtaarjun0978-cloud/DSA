class Solution {
public:
    int numberOfSubstrings(string s) {
        //make a hash map to count frequency of char / but we have fixed characters we can use vector also

        vector<int> freq(3,0);
        int left = 0 ;
        int ans = 0 ;
        int n = s.size() ;

        for(int right = 0 ; right <n ; right++){
            freq[s[right] - 'a']++;

            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                ans += (n - right);

                //now you can shrink the window down
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};