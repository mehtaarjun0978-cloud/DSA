class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ; 

        vector<int> result(n , -1);

        std::stack<int> s ; // stores the elements 

        for(int i = (2*n)-1 ; i >= 0 ; i--){

            // get the index ind
            int ind = i%n ;
            //get current element
            int curEle = nums[ind] ;

            while( !s.empty() && curEle >= s.top() ) {
                // pop the elements 
                s.pop();
            }

            // store the answers for 1st half 
            if( i < n ){
                if( !s.empty() ) {
                    result[i] = s.top();
                }
            }

            //push the currenet element in the stack 
            s.push(curEle);
        }
        return result;
    }
};