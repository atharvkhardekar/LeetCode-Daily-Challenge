// LeetCode Problem No. 2182
// Daily Challenge - 17/12/2024

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
    
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({char('a' + i), freq[i]});  
            }
        }
        string result = "";
        
        while (!pq.empty()) {
            auto [ch1, count1] = pq.top();
            pq.pop();
            
            int useCount = min(repeatLimit, count1);
            result.append(useCount, ch1);
            count1 -= useCount;
            
            if (count1 > 0) {
                if (pq.empty()) break; 
                
                auto [ch2, count2] = pq.top();
                pq.pop();
                result.push_back(ch2);
                count2--;
                
                if (count2 > 0) pq.push({ch2, count2});
                pq.push({ch1, count1});
            }
        }
        return result;
    }
};