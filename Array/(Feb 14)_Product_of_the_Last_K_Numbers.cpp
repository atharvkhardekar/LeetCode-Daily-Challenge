// LeetCode Problem No. 1352
// Daily Challenge - 14/02/2025

class ProductOfNumbers {
    vector<int> stream = {1};
    int n;
    int last_zero_idx;

 public:
    ProductOfNumbers() {
        n = 1;
        last_zero_idx = -1;
    }
    
    void add(int num) {
        if (num == 0) {
            last_zero_idx = n;
        }

        if (stream.back() == 0) {
            stream.push_back(num);
        } else {
            stream.push_back(stream.back() * num);
        }
        n++;
    }
    
    int getProduct(int k) {
        if (last_zero_idx >= n - k) {
            return 0;
        }
        if (stream[n - k - 1] == 0) {
            return stream[n - 1];
        } else {
            return stream[n - 1] / stream[n - k - 1];
        }
    }
};
