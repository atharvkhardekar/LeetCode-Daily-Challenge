// LeetCode Problem No. 1455
// Daily Challenge - 02/12/2024

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1; 
        size_t pos = 0; 
        
        while (pos < sentence.length()) {
            size_t spacePos = sentence.find(' ', pos);
            string word = sentence.substr(pos, spacePos - pos);

            if (word.find(searchWord) == 0) {
                return index;
            }

            pos = (spacePos == string::npos) ? spacePos : spacePos + 1;
            index++;
        }
        return -1; 
    }
};