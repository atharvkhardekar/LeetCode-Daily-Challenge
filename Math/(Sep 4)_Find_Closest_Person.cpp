// LeetCode Problem No. 3516
// Daily Challenge - 04/09/2025

class Solution {
public:
    int findClosest(int x, int y, int z) {

        int disX = abs(z-x);
        int disY = abs(z-y);

        if(disX > disY) return 2;
        else if(disY > disX) return 1;
        else return 0;
    }
};