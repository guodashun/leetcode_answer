class Djset {
public:
    vector<int> parent;
    vector<int> rank;
    Djset(int n ) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                swap(rx, ry);
            }
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[x] += 1;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<char> rs(n);
        Djset ds(n);
        for (const auto& e : pairs) ds.merge(e[0], e[1]);
        
        //  格式化并查集，即哪些下标可以交换
        unordered_map<int, vector<int> > um;
        for (int i = 0; i < n; i++) um[ds.find(i)].push_back(i);
        
        // 同一并查集按字典序排序
        for (auto& [k, v] : um) {
            vector<int> c = v;
            sort(v.begin(), v.end(), [&](auto a, auto b) {
                return s[a] < s[b];
            });
            for (int i = 0; i < c.size(); i++) rs[c[i]] = s[v[i]];
        }
        
        s = "";
        for (const auto& e : rs) s += e;
        return s;
    }
};

// 以为可以回溯剪枝，但想了想有难度，并查集最舒服
