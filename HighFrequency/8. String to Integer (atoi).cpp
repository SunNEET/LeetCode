class Solution {
    // 用跟 No.65 Valid Number 類似的想法來解，利用DFA來設計狀態和移轉
    // s0: 起始狀態, 吃到空格維持不變, +-到s1, digit到s2
    // s1: 有一個符號的valid狀態, 再吃到一個符號或空白變到s3, digit到s2
    // s2: 有數字的valid狀態, 吃到數字維持不變, 吃到其他的就到s3
    // s3: invalid的狀態
    // 只有在 valid 狀態才把切割字串的 pointer 往後加, invalid 就減回來然後 break

    // ** 要處理溢位，且題目規定只能用32bits的型別
    // 所以用 a > INT_MAX/10 來判斷乘法結果會不會溢位
    // a > INT_MAX - val 來判斷加法
public:
    int parse(string str) {
        int res = 0, sign = 1;
        for(int i=0;i<str.length();i++) {
            char c = str[i];
            if(c == '-')
                sign = -1;
            else if(c == '+')
                continue;
            else {
                // checked overflow under 32bits system
                int val = c - '0';
                if(res > (INT_MAX/10)) {
                    return sign == 1 ? INT_MAX: INT_MIN;
                } else 
                    res *= 10;
                if(res > INT_MAX - val)
                    return sign == 1 ? INT_MAX: INT_MIN;
                else
                    res += val;
            }
        }
        return res*sign;
    }
    int myAtoi(string str) {
        enum InputType {
            INVALID,
            SPACE,
            SIGN,
            DIGIT
        };
        const int transitionTable[][4] = {
            {3,0,1,2}, // s0
            {3,3,3,2}, // s1
            {3,3,3,2}, // s2
            {3,3,3,3} // s3
        };
        int state=0, s=0, e=0;
        for(int i=0;i<str.length();i++) {
            char c = str[i];
            InputType inputType = INVALID;
            if(isspace(c))
                inputType = SPACE;
            else if(c=='+' || c=='-')
                inputType = SIGN;
            else if(isdigit(c))
                inputType = DIGIT;
            
            state = transitionTable[state][inputType];
            if(state==0) {
                s++; e++;
            } else if(state==1){
                e++;
            } else if(state==2) {
                e++;
            } else {
                e--;
                break;
            }
        }
        
        return parse(str.substr(s, e-s+1));
    }
};