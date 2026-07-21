class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk; 

        for(char c : s) {
            // 1. Push opening brackets
            if(c == '(' || c == '[' || c == '{') {
                stk.push(c);
            }
            else {
                // 2. Prevent crash: check if stack is empty before checking top
                if(stk.empty()) {
                    return false;
                }

                // 3. Fix C++ pop: get the top element first, then pop it
                char ch = stk.top();
                stk.pop();

                // 4. Fix logic: Ensure the pairs match correctly
                if (c == ')' && ch != '(') return false;
                if (c == ']' && ch != '[') return false;
                if (c == '}' && ch != '{') return false;
            }
        }

        // 5. More concise return statement
        return stk.empty();
    }
};