// LeetCode Problem No. 2011
// Daily Challenge - 20/10/2025

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0; 
        for (string op : operations) {
            if (op == "++X" || op == "X++")
                X += 1; 
            else
                X -= 1; 
        }
        return X;
    }
};