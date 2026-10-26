class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // Push the expected closing bracket onto the stack
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } 
            // If it's a closing bracket, check for a match
            else {
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop(); // Match found, remove it from the stack
            }
        }
        
        // If stack is empty, all brackets were correctly matched
        return st.empty();
    }
};