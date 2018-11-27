class Solution {
    /*
        clarify:
        (1) Will the input string contain other characters other than brackets? 
        (2) What if input string is empty? What should I return?
    */
public:
    bool isValid(string s) {
        if(s == "") return true;
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(')
                st.push(')');
            else if(s[i] == '{')
                st.push('}');
            else if(s[i] == '[')
                st.push(']');
            else {
                if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    if(st.empty() || s[i] != st.top())
                        return false;
                    else
                        st.pop();
                }
            }
        }
        return st.empty();
    }
};