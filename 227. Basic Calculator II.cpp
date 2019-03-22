class Solution {
    /*
        目標是把乘法跟除法的操作在掃過去的時候就處理好，將 result push 進 stack 裡
        普通的加跟減也就是 push 數字進去而已，這樣最後把 stack 裡的數字 add up 就好了
        
        對當前的數字做操作的時機，是在遇到下個運算符號or到尾巴的時候
        e.g. 1+2*3, 一開始都把第一個數字前的op符號當作'+'來方便計算
        所以會是 + 1 - 2 * 3
        此時的op ^ ^ ^
        目前的 num ^ ^ 
                    ^ op = '-', num = 0
        當遇到下個符號或盡頭的時候，就對目前的 num 做操作，然後op更新成目前ch的op
            
        
        坑點：用 switch case 的時候要注意裡面不能宣告變數，不然就要用{} enclose 起來
        理想是設在switch外面

    */
public:
    int calculate(string s) {
        int num = 0, sum = 0;
        stack<int> st;
        char op = '+';
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(isdigit(ch))
                num = num*10 + (ch-'0');
            if(i==s.length()-1 || (!isdigit(ch) && ch!=' ') ) {
                int num2;
                switch(op) {
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        num2 = st.top();
                        st.pop();
                        st.push(num2*num);
                        break;
                    case '/':
                        num2 = st.top();
                        st.pop();
                        st.push(num2/num);
                        break;
                }
                op = ch;
                num = 0;
            }
        }
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};


class Solution {
    /*
        不用 stack 的做法：
        因為 stack 存起來的值最後也只是把他們加總而已，我們其實可以邊做邊加總。
        關鍵在於遇到像 * 和 / 的時候，再遇到下一個 +,- 或到盡頭之前，
        都會繼續加總到目前的暫時總和上。
        如果下一個op是 +,- 或已經超過盡頭的話，就把目前累計的 cur_sum 加到 sum 上
        e.g. 102-21*34/4+5
             ^
                ^下個op是+/-就直接把目前的結果加總
                   ^下個op是乘除就把目前的結果留著，給他們在下個loop做乘除
        坑點1: i 最後會超過 s.length()-1，所以判斷到結尾了要用 >=
    */
public:
    int calculate(string s) {
        int sum = 0, cur_sum = 0;
        char op = '+';
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(isdigit(s[i])) {
                int num = c-'0';
                while(++i<s.length() && isdigit(s[i]))
                    num = num*10+s[i]-'0';
                switch(op) {
                    case '+': cur_sum = num; break;
                    case '-': cur_sum = -num; break;
                    case '*': cur_sum*= num; break;
                    case '/': cur_sum/= num; break;
                }
            }
            if(s[i]!=' ' && !isdigit(s[i])) {
                if(s[i]=='+' || s[i]=='-') {
                    sum += cur_sum;
                    cur_sum = 0;
                }
                if(i>=s.length()-1) {
                    sum += cur_sum;
                    break;
                }          
                op = s[i];
            }
        }
        return sum;
    }
};