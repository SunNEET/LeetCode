class Solution {
    // 模擬題 直接做
public:
    bool isValid(string s) {
        if(s.length()==0) return true;
        stack<char> st;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else {
                if(st.empty()) return false;
                char tp = st.top();
                if(s[i]==')') {
                    if(tp=='(')
                        st.pop();
                    else
                        return false;
                }
                if(s[i]=='}') {
                    if(tp=='{')
                        st.pop();
                    else
                        return false;                    
                }
                if(s[i]==']') {
                    if(tp=='[')
                        st.pop();
                    else
                        return false;                    
                }                
            }
        }
        return st.empty();
    }
};