// LeetCode Problem No. 3100
// Daily Challenge - 02/10/2025

class Solution{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int bottleDrunk = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange)
        {
            emptyBottles -= numExchange;
            numExchange++;
            bottleDrunk++;
            emptyBottles++;
        }
        return bottleDrunk;
    }
};