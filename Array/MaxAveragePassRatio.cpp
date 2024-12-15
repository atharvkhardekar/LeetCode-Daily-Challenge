// LeetCode Problem No. 1792
// Daily Challenge - 15/12/2024

class Solution {
    #define PairGainIndex pair<double, int>

    void calculateGain(priority_queue<PairGainIndex>& maxHeap, vector<vector<int>>& classes, int index) {
        double currentRatio = (double)classes[index][0] / classes[index][1];
        double updatedRatio = ((double)classes[index][0] + 1) / (classes[index][1] + 1);
        double gain = updatedRatio - currentRatio;
        maxHeap.push(make_pair(gain, index));
    }

 public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int numberOfClasses = classes.size();
        priority_queue<PairGainIndex> maxHeap;
        
        for (int i = 0; i < numberOfClasses; ++i)
            calculateGain(maxHeap, classes, i);
        
         while (extraStudents--) {
            PairGainIndex topClass = maxHeap.top();
            maxHeap.pop();

            int index = topClass.second;
            classes[index][0]++;
            classes[index][1]++;
            calculateGain(maxHeap, classes, index);
         }

         double averageRatio = 0.0;
         for (int i = 0; i < numberOfClasses; ++i)
            averageRatio += (double)classes[i][0] / classes[i][1];

        return averageRatio / numberOfClasses;
    }
};
