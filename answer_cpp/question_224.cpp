class Solution {
public:
    int calculate(string s) {
        stack<char> sign;
        stack<int> nums;
        int i = 0, s_len = s.size();
        while(i < s_len){
            if(s[i] == '(' || s[i] == '+' || s[i] == '-') sign.push(s[i]);
            else if(isdigit(s[i])){
                int temp = 0;
                while(i < s_len && isdigit(s[i])) temp = temp * 10 + (s[i++]-'0');
                i--;
                if(sign.empty() || sign.top() == '(') nums.push(temp);
                else{
                    int nums_top = nums.top(); nums.pop();
                    char sign_top = sign.top(); sign.pop();
                    if(sign_top == '+') nums.push(nums_top + temp);
                    else if(sign_top == '-') nums.push(nums_top - temp);
                }
            }
            else if(s[i] == ')'){
                sign.pop();
                if(sign.empty() || sign.top() == '(') ;
                else{
                    int nums_top2 = nums.top(); nums.pop();
                    int nums_top1 = nums.top(); nums.pop();
                    char sign_top = sign.top(); sign.pop();
                    if(sign_top == '+') nums.push(nums_top1 + nums_top2);
                    else if(sign_top == '-') nums.push(nums_top1 - nums_top2);
                }
            }
            i++;
        }
        return nums.top();
    }
};

// 单栈迭代易超时
// 双栈是普遍解法