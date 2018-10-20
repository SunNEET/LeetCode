class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for(int i=0;i<s.length();i++) {
            char c = s[i];
            if(c=='{'||c=='['||c=='(')
                sc.push(c);
            else {
                // 避免top()時沒東西而報錯
                if(sc.size()>0) {
                    if(c=='}') {
                        if(sc.top() == '{') 
                            sc.pop();
                        else
                            return false;
                    } else if(c==']') {
                        if(sc.top() == '[')
                            sc.pop();
                        else
                            return false;
                    } else if(c==')') {
                        if(sc.top()=='(')
                            sc.pop();
                        else
                            return false;
                    }   
                } else
                    return false;
            }
        }
        return sc.size() == 0;
    }
};