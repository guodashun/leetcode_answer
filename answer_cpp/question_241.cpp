class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 1; i < input.size(); i++) {
            auto ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                auto left = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        if (ch == '+') {
                            res.push_back(left[j] + right[k]);
                        }
                        else if (ch == '-') {
                            res.push_back(left[j] - right[k]);
                        } else if (ch == '*') {
                            res.push_back(left[j] * right[k]);
                        } else {
                            assert(false && "Unexpected operator char!");
                        } 
                    }
                }
            }
        }

        // Recursion exit (Base case)
        if (res.empty()) {
            return {stoi(input)};
        }

        return res;
    }
};

// water