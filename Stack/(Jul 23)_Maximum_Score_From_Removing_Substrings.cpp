// LeetCode Problem No. 1717
// Daily Challenge - 23/07/2025

class Solution {
public:
    int removeSubstring(string& s, char first, char second, int score) {
        stack<char> st;
        int points = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                points += score;
            } else {
                st.push(c);
            }
        }

        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return points;
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            total += removeSubstring(s, 'a', 'b', x);  
            total += removeSubstring(s, 'b', 'a', y);  
        } else {
            total += removeSubstring(s, 'b', 'a', y); 
            total += removeSubstring(s, 'a', 'b', x);  
        }

        return total;
    }
};
