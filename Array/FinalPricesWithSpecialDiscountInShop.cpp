// LeetCode Problem No. 1475
// Daily Challenge - 18/12/2024

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices);  
        stack<int> s; 

        for (int i = 0; i < n; i++) {
            while (!s.empty() && prices[s.top()] >= prices[i]) {
                int idx = s.top();
                s.pop();
                result[idx] -= prices[i];  
            }
            s.push(i);
        }
        return result;
    }
};