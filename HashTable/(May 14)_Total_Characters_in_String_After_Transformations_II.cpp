// LeetCode Problem No. 3337
// Daily Challenge - 14/05/2025

class Solution {
    using Matrix = array<array<int, 26>, 26>;
    int MOD = 1e9 + 7;

    inline Matrix matrixMultiplication(Matrix& A, Matrix& B) {
        Matrix res{};
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    res[i][j] = (res[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    inline Matrix matrixExponentiation(Matrix& transformation_matrix, int t) {
        Matrix res{};
        for (int i = 0; i < 26; ++i) {
            res[i][i] = 1;
        }

        while (t) {
            if (t & 1) {
                res = matrixMultiplication(transformation_matrix, res);
            }
            transformation_matrix = matrixMultiplication(transformation_matrix, transformation_matrix);
            t /= 2;
        }

        return res;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        array<int, 26> initial_freq{};
        for (char c : s) {
            initial_freq[c - 'a']++;
        }

        Matrix transformation_matrix{};
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j <= i + nums[i]; ++j) {
                transformation_matrix[j % 26][i]++;
            }
        }

        Matrix res = matrixExponentiation(transformation_matrix, t);

        array<int, 26> final_array{};
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                final_array[i] = (final_array[i] + (1LL * res[i][j] * initial_freq[j]) % MOD) % MOD;
            }
        }

        int string_size = 0;
        for (int i = 0; i < 26; ++i) {
            string_size = (string_size + final_array[i]) % MOD;
        }

        return string_size;
    }
};
