// LeetCode Problem No. 11
// Daily Challenge - 04/10/2025

class Solution{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left <= right)
        {
            int minHeight = min(height[left], height[right]);
            int width = right - left;
            int area = minHeight * width;
            maxArea = max(maxArea, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};