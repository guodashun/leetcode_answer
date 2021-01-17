class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        if (size <= 2) return true;
        if (coordinates[1][0] == coordinates[0][0]) {
            for (int i = 1; i < size-1; i++) {
                if (coordinates[i+1][0] != coordinates[i][0]) return false;
            }
        }
        else {
            double k = double(coordinates[1][1] - coordinates[0][1]) /  double(coordinates[1][0] - coordinates[0][0]);
            for (int i = 1; i < size - 1; i++) {
                if (coordinates[i+1][0] == coordinates[i][0] || (double((coordinates[i+1][1] - coordinates[i][1]) /  double(coordinates[i+1][0] - coordinates[i][0])) != k)) return false;
            }
        }
        return true;
    }
};

// 整形除法...斜率为无穷...

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        /*
        *   一般式：Ax+By+C=0（AB≠0）
        *   两点式：(y-y1)/(x-x1)=(y-y2)/(x-x2) 　（直线过定点(x1,y1),(x2,y2)）
        */

        // 这里取定点为coordinates[0],和coordinates[n-1]
        // 为避免除法运算，这里用“两内项的积等于两外项的积”计算
        int n = coordinates.size();
        for(int i = 1; i < coordinates.size()-1; ++i)
        {
            if(
                (coordinates[i][0] - coordinates[0][0])*    /* (x-x1)*(y-y2) */
                (coordinates[i][1] - coordinates[n-1][1])
                !=
                (coordinates[i][1] - coordinates[0][1])*    /* (y-y1)*(x-x2) */
                (coordinates[i][0] - coordinates[n-1][0])

            )   return false;
        }
        return true;
    }
};

// 拒绝除法（然而这就是数学题  好像没太大意义）
