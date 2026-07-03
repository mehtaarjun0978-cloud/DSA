class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        //here we will use the same concept of p_sum and the hasmap 
        map <int,int> mpp;     //map< remainder , index >
        mpp[0] = -1;

        int psum = 0 ;

        for(int j = 0 ; j<nums.size() ; j++){
            psum += nums[j];
            int remainder = psum % k ; //we will get the remainder 
            
            //if remainder is already present in hashmap then we have to just remove the first occarance of that remainder 
            
            //we have to store the key:vlaue at the map
            //if matching key found then it will return the iterator pointing to matched value otherwise it willl return the end point of the map

            if(mpp.find(remainder) != mpp.end())
            {   
                int indx = mpp[remainder];
                if((j-indx) >=2){
                      return true ;
                }
            }
            else {
                mpp[remainder] = j;
            }
        }    
        return false;     
    }
};