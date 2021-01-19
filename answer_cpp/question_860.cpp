class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) mp[5]++;
            if (bills[i] == 10) {
                mp[10]++;
                if (mp[5] <= 0) return false;
                else mp[5]--;
            }
            if (bills[i] == 20) {
                mp[20]++;
                if (mp[10] >=1 && mp[5] >= 1) {
                    mp[10]--;
                    mp[5]--;
                } else if (mp[5] >= 3) {
                    mp[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

// 没必要用map...直接定义变量就好

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto& bill: bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    } 
};
