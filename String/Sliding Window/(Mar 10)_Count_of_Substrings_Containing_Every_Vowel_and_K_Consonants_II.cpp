// LeetCode Problem No. 3306
// Daily Challenge - 10/03/2025

class Solution {
    #define ll long long

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    void findNextConsonant(string& word, vector<int>& next_consonant) {
        int n = word.size();
        int next = n;
        
        for (int i = n - 1; i >= 0; --i) {
            next_consonant[i] = next;
            if (!isVowel(word[i])) {
                next = i;
            }
        }
    }

 public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> next_consonant(n);
        findNextConsonant(word, next_consonant);

        ll count = 0;
        int consonants = 0;
        unordered_map<char, int> vowel_freq;
        int left = 0;
        int right = 0;
        int prev = -1;

        while (right < n) {
            if (prev != right) {
                if (isVowel(word[right])) {
                    vowel_freq[word[right]]++;
                } else {
                    consonants++;
                }
                prev = right;
            }

            if (right >= (5 + k - 1)) {
                if (vowel_freq.size() == 5 && consonants == k) {
                    count += next_consonant[right] - right;
                }

                if ((vowel_freq.size() == 5 && consonants == k) || (consonants > k)) {
                    if (isVowel(word[left])) {
                        vowel_freq[word[left]]--;
                        if (vowel_freq[word[left]] == 0) {
                            vowel_freq.erase(word[left]);
                        }
                    } else {
                        consonants--;
                    }
                    left++; 
                } else {
                    right++; 
                }
            } else {
                right++; 
            }
        }

        return count;
    }
};
