// LeetCode Problem No. 1792
// Daily Challenge - 01/09/2025

class Solution{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        auto cmp = [](const vector<double> &a, const vector<double> &b)
        {
            return a[0] < b[0]; 
        };
        priority_queue<vector<double>, vector<vector<double>>, decltype(cmp)> pq(cmp);

        for (auto &arr : classes)
        {
            int pass = arr[0], total = arr[1];
            double gain = findGain(pass, total);
            pq.push({gain, (double)pass, (double)total});
        }

        while (extraStudents-- > 0)
        {
            auto top = pq.top();
            pq.pop();
            int pass = (int)top[1] + 1;
            int total = (int)top[2] + 1;
            double gain = findGain(pass, total);
            pq.push({gain, (double)pass, (double)total});
        }

        double res = 0.0;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            res += top[1] / top[2];
        }
        return res / classes.size();
    }

private:
    double findGain(int pass, int total)
    {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }
};
