class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.empty()) return 0;
        sort(answers.begin(), answers.end());
        int cur = -1, cnt = 0;
        int res = 0;
        int sz = answers.size();
        for (int i = 0; i < sz; i++) {
            if (answers[i] > cur || cnt <= 0) {
                res += (answers[i] + 1);
                cur = answers[i];
                cnt = answers[i];
            } else {
                cnt--;
            }
        }
        return res;
    }
};

// 排序+计数器
// 没必要排序 直接计数器

class Solution {
    public int numRabbits(int[] answers) {
//m[i]>0   先前已经记录到有回答i的兔子,这次遇到只需容量减1
//m[i]==0  第一次遇到回答i的兔子或者上一次遇到回答i的兔子时创建颜色的容量已经用完. 
           创建新的颜色,容量为i,并将这一波兔子数量加到结果中
        int[] m = new int[1000];
        int result = 0;
        for (int i : answers) {
            if (m[i] > 0) {
                m[i]--;
            } else {
                m[i] = i;
                result += i + 1;
            }
        }
        return result;
    }
}
