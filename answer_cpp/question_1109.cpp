class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int size = bookings.size();
        vector<int> diff(n+1,0);
        for (int i = 0; i < size; i++) {
            int start = bookings[i][0];
            int end = bookings[i][1];
            diff[bookings[i][0]-1] += bookings[i][2];
            diff[bookings[i][1]] -= bookings[i][2];
        }
        vector<int> res(n,0);
        res[0] = diff[0];
        if(n>1)
        for (int i = 1; i<n; i++) {
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};

// 自己丑陋的解法

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n,0);
        for(int i=0;i<bookings.size();i++){
            res[bookings[i][0] - 1] += bookings[i][2];
            if(bookings[i][1] < n){
                res[bookings[i][1]] -= bookings[i][2];
            }
        }

        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
        }
        return res;   
    }
};

// 大佬解法，直接利用一个数组解决问题，自己从差分变成正常

作者：zhang-xu-dong
链接：https://leetcode-cn.com/problems/corporate-flight-bookings/solution/gong-jiao-che-suan-fa-xiang-jie-by-zhang-xu-dong/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
