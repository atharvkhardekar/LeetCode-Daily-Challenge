// LeetCode Problem No. 1346
// Daily Challenge - 01/12/2024

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;

        for(int i=0; i<arr.size(); i++){
            if(seen.count(2*arr[i]) || (arr[i] % 2 == 0 && seen.count(arr[i]/2))){
                return true;
            }   
            seen.insert(arr[i]);
        }
        return false;
    }
};