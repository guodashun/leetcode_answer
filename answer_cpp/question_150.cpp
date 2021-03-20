class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (s == "+" || s == "-" || s == "*" || s == "/"){
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                int res = 0;
                char c = s[0];
                switch (c){
                    case '+':
                        res = a + b;
                        break;
                    case '-':
                        res = a - b;
                        break;
                    case '*':
                        res = a * b;
                        break;
                    case '/':
                        res = a / b;
                        break;
                    default:
                        break;
                }
                num.push(res);
            } else num.push(stoi(s));
        }
        return num.top();
    }
};

// string to int -> stoi(str)
// stack void pop()  <T> top() 先top后pop()
