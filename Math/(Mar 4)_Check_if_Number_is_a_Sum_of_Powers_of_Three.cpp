// LeetCode Problem No. 1780
// Daily Challenge - 04/03/2025

class Solution {
    public:
       bool checkPowersOfThree(int n) {
           while (n > 0) {
               if (n % 3 == 2)  
                   return false;
               n /= 3;
           }
           return true;
       }
   };
   