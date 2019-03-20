class Solution {
    /*
        用map來simplify
    */
public:
    bool isValid(string s) {
        if(s=="") return true;
        stack<char> st;
        unordered_map<char, char> mp = {{'(',')'},{'[',']'},{'{','}'}};
        for(int i=0; i<s.length(); i++) {
            if(mp.count(s[i])) 
                st.push(mp[s[i]]);
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

class Solution {
    /*
        簡潔的寫法，不 push 左括號而是右括號，這樣判斷右括號合不合法只要看目前 top 是不是跟自己一樣的就好
        clarify:
        (1) Will the input string contain other characters other than brackets? 
        (2) What if input string is empty? What should I return?
    */
public:
    bool isValid(string s) {
        if(s=="") return true;
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
        return true;
    }
};