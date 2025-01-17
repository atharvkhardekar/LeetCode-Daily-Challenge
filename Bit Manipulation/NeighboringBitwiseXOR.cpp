// LeetCode Problem No. 2683
// Daily Challenge - 17/01/2025

// There should be valid array for derived array if the XOR of all the elements in derived array is 0.
// (a^b)^(b^c)^(c^a) = 0

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res=0;
        for(int ele: derived)
            res^=ele;
        
        return res==0;
    }
};