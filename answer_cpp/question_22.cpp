class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string track="";
        backawrd(track, n,n,n);
        return res;
    }
    void backawrd(string& track, int left, int right, int n) {
        if (track.size() == n*2) {res.push_back(track); return;}
        // if (left < 0 ||  right < 0) return;
        if (right < left) return;
        if (left > 0) {
            track += "(";
            
            backawrd(track, left-1, right,n);
            track.pop_back();
        }
        if (right > 0) {
            track += ")";
            
            backawrd(track, left, right-1,n);
            track.pop_back();
        }
    }
};

// for循环是为了做选择  这个题就俩选择  可以不用for循环
// 不要++ -- 会影响后面的选择
