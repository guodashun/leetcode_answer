class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> count;
        for (string &word: words) {
            int mask = 0;
            for (char ch : word)
                mask |= (1 << (ch - 'a'));
            ++count[mask];
        }
        
        int n = puzzles.size();
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            string &puzzle = puzzles[i];
            int k = 0;
            for (char ch: puzzle) {
                k |= (1 << (ch - 'a'));
            }

            int sub = k;
            do {
                sub = (sub - 1) & k;
                // 首字母必须出现
                if ((1 << (puzzle[0] - 'a')) & sub)
                    ret[i] += count[sub];
            } while (sub != k);
        }
        return ret;
    }
};

// cv快乐
