// LeetCode Problem No. 916
// Daily Challenge - 10/01/2025

class Solution {
private:
    vector<int> getFrequency(const string& word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        return freq;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for (const string& b : words2) {
            vector<int> freq = getFrequency(b);
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> result;
        for (const string& a : words1) {
            vector<int> freq = getFrequency(a);
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(a);
            }
        }
        return result;
    }
};