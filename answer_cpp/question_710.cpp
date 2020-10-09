class Solution {
public:
    unordered_map<int, int> hash;
    int size = 0;
    Solution(int N, vector<int>& blacklist) {
        size = N - blacklist.size();
        for (auto& b : blacklist) {
            hash[b] = 777;
        }
        int last = N-1;
        for (auto& b : blacklist) {
            if (b >= size) {
                continue;
            }
            while(hash.count(last)) {
                last--;
            }
            hash[b] = last;
            last--;
        }
    }
    
    int pick() {
        int res = rand() % size;
        if (hash.count(res)) return hash[res];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

// 参考380的思路
// 直接映射黑名单到白名单，不需要remove，虽然更好理解
// 映射的时候需要注意一些情况
