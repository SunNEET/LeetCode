class Solution {
public:
    bool isNumber(string s) {
        // 一個數字的構成 = 符號 + 浮點數 + e + 符號 + 整數
        // 用 DFA 來處理這個問題會比較容易，可以把每個字元的輸入看成狀態的input，讓他發生轉移
        // 先整裡一下怎麼設定不同狀態，再來設定彼此之間怎麼移轉，做題前把狀態機先畫出來
        // s0: 起始狀態 (什麼都沒有)
        // s1: 前半部有了"+-"符號 ("+" or "-" or "    +"...)
        // s2: 前半部有了數字("12" or "  1" or " -3" or "+445") (accept)
        // s3: 有了e 以此區分前後半部("12e" or "   1e" or "  -3e")
        // s4: 後半部有了"+-"符號("12e+" or "  1e-" or "  -3e+")
        // s5: 後半部有了數字("12e+22", "  1e-3", "  -3e+1")(accept)
        // s6: 前半部有了"."("12.", "  1.", "  -3.", "+445.")
        // s7: 前半部"."後面的數字("12.3", "  1.")
        // s8: 後半部的數字+了空白
        // s9: .前沒有數字
        enum InputType {
            INVALID,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXPONENT
        };
        const int transitionTable[][6] = {
            {-1, 0, 1, 2, 9, -1}, // s0 吃到各種input時會前往的狀態
            {-1, -1, -1, 2, 9, -1}, // s1
            {-1, 8, -1, 2, 6, 3}, // s2
            {-1, -1, 4, 5, -1, -1}, // s3
            {-1, 8, -1, 5, -1, -1}, // s4
            {-1, 8, -1, 5, -1, -1}, // s5
            {-1, 8, -1, 7, -1, 3}, // s6
            {-1, 8, -1, 7, -1, 3}, // s7
            {-1, 8, -1, -1, -1, -1}, // s8
            {-1, -1, -1, 7, -1, -1} // s9
        };
        int state = 0;
        for(char c : s) {
            InputType inputType = INVALID;
            if(isspace(c))
                inputType = SPACE;
            else if(c=='+'||c=='-')
                inputType = SIGN;
            else if(isdigit(c))
                inputType = DIGIT;
            else if(c=='.')
                inputType = DOT;
            else if(c=='e')
                inputType = EXPONENT;
            state = transitionTable[state][inputType];
            
            if(state==-1) return false;
        }
        
        
        return state==2 || state==6 || state==7 || state==5 || state == 8;
    }
};