class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) return 0;
        int size = timeSeries.size();
        int last = timeSeries[0];
        int res = 0;
        for (int i =0; i < size; i ++) {
            int diff = timeSeries[i] - last;
            if (diff >= duration) res += duration;
            else res+= diff;
            last = timeSeries[i];
        }
        res += duration;
        return res;
    }
};

// finish

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size();
        if(len == 0){
            return len;
        }
        int sum = 0;
        for(int i=1;i<len;i++){
            sum += min(timeSeries[i]-timeSeries[i-1],duration);
        }
        return sum + duration;
    }
};

// 不需要last 直接min比较
