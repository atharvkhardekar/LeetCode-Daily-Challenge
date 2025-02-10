// LeetCode Problem No. 3174
// Daily Challenge - 10/02/2025

class Solution {
    public:
        string clearDigits(string s) {
            stack<char> st;
            
            for (char c : s) {
                if (isdigit(c)) {
                    if (!st.empty()) {
                        st.pop(); 
                    }
                } else {
                    st.push(c); 
                }
            }
            
            string result;
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            
            reverse(result.begin(), result.end());
            return result;
        }
    };
    