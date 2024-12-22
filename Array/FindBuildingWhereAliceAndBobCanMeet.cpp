// LeetCode Problem No. 2940
// Daily Challenge - 22/12/2024

class Solution {
    vector<int> segmentTree; 

    void constructSegmentTree(vector<int>& buildings, int left, int right, int index) {
        if (left == right) {
            segmentTree[index] = left;
            return;
        }

        int mid = left + (right - left) / 2;
        constructSegmentTree(buildings, left, mid, 2 * index);
        constructSegmentTree(buildings, mid + 1, right, 2 * index + 1);

        segmentTree[index] = buildings[segmentTree[2 * index]] >= buildings[segmentTree[2 * index + 1]] ?
                             segmentTree[2 * index] : segmentTree[2 * index + 1];
    }

    int queryMaxInRange(vector<int>& buildings, int queryStart, int queryEnd, int left, int right, int index = 1) {
        if (left >= queryStart && right <= queryEnd) 
            return segmentTree[index];
        if (left > queryEnd || right < queryStart) 
            return INT_MIN;

        int mid = left + (right - left) / 2;
        int leftMax = queryMaxInRange(buildings, queryStart, queryEnd, left, mid, 2 * index);
        int rightMax = queryMaxInRange(buildings, queryStart, queryEnd, mid + 1, right, 2 * index + 1);

        if (leftMax == INT_MIN) return rightMax;
        if (rightMax == INT_MIN) return leftMax;
        return buildings[leftMax] >= buildings[rightMax] ? leftMax : rightMax;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& buildings, vector<vector<int>>& queries) {
        int size = buildings.size();
        segmentTree = vector<int>(4 * size + 1);
        int rootIndex = 1; 

        constructSegmentTree(buildings, 0, size - 1, rootIndex);

        vector<int> result;
        for (auto query : queries) {
            int alice = min(query[0], query[1]);
            int bob = max(query[0], query[1]);

            if (alice == bob || buildings[bob] > buildings[alice]) {
                result.push_back(bob);
                continue;
            }

            int low = bob;
            int high = size - 1;
            int answer = INT_MAX;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int rmq = queryMaxInRange(buildings, low, mid, 0, size - 1, rootIndex);

                if (buildings[rmq] > buildings[alice]) {
                    high = mid - 1;
                    answer = min(answer, rmq);
                } else {
                    low = mid + 1;
                }
            }
            if (answer == INT_MAX) result.push_back(-1);
            else result.push_back(answer);
        }
        return result;
    }
};
