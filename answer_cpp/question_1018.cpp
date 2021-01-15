class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int sum = 0;
        for (int i = 0; i<A.size(); i++) {
            sum = (sum * 2 + A[i]) % 10;
            if (sum % 5 == 0) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};

// long long 都会溢出  其实不用考虑所有  只考虑末位就好
