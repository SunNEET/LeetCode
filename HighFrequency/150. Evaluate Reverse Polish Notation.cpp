class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}},
            {"*", [](int a, int b){return a*b;}},
            {"/", [](int a, int b){return a/b;}}
        };
        stack<char> stack;
        for (string& s : tokens) {
            // 數字的情況
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else { //+-*/的情況
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};