// LeetCode Problem No. 37
// Daily Challenge - 31/08/2025

class Solution{
    unsigned Row[9] = {0};
    unsigned Col[9] = {0};
    unsigned Block[9] = {0};
    vector<pair<char, char>> uncertain;

public:
    void print(vector<vector<char>> &board)
    {
        for (vector<char> &row : board)
        {
            for (char &c : row)
                cout << c;
            cout << endl;
        }
        cout << "===========\n";
    }
    void set3Cond(int i, int j, int x)
    {
        const int x2 = 1 << x;
        Row[i] |= x2;
        Col[j] |= x2;
        const int bidx = (i / 3) * 3 + j / 3;
        Block[bidx] |= x2;
    }

    void setup(vector<vector<char>> &board)
    {
        uncertain.reserve(81);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c == '.')
                {
                    uncertain.emplace_back(i, j);
                }
                else
                {
                    set3Cond(i, j, c - '1');
                }
            }
        }
    }

    bool solve(vector<vector<char>> &board, int idx)
    {
        if (idx == uncertain.size())
            return 1;
        auto [i, j] = uncertain[idx];
        const int bidx = (i / 3) * 3 + j / 3;
        unsigned notMask = ~(Row[i] | Col[j] | Block[bidx]) & 0b111111111;
        unsigned Bit = 0;
        for (; notMask; notMask ^= Bit)
        {
            Bit = bit_floor(notMask);
            const int x = countr_zero(Bit);

            board[i][j] = '1' + x;
            Row[i] |= Bit;
            Col[j] |= Bit;
            Block[bidx] |= Bit;
            if (solve(board, idx + 1))
                return 1;
            Row[i] ^= Bit;
            Col[j] ^= Bit;
            Block[bidx] ^= Bit; 
            board[i][j] = '.';
        }
        return 0;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        setup(board);
        solve(board, 0);
    }
};
