class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left=INT_MAX,right=INT_MIN;
        int bottom=INT_MAX,top=INT_MIN;
        int s=0;
        map<pair<int,int>,int> m;   //保存每个顶点数量
        for(vector<int>& a:rectangles){
            left = min(left,a[0]);  //找最大矩形
            right= max(right,a[2]);
            bottom=min(bottom,a[1]);
            top  = max(top,a[3]);
            s+=(a[2]-a[0])*(a[3]-a[1]);
            m[{a[0],a[1]}]++;   //保存4个顶点
            m[{a[2],a[3]}]++;
            m[{a[0],a[3]}]++;
            m[{a[2],a[1]}]++;
        }
        if(s != (right-left)*(top-bottom))return false;
        m[{left,bottom}]++; //把大矩形有4个角放入后,所有点都应该是偶数了
        m[{left,top}]++;
        m[{right,bottom}]++;
        m[{right,top}]++;
        for(auto it=m.begin();it != m.end(); it++)if((*it).second %2 ==1)return false;
        return true;
    }
};
