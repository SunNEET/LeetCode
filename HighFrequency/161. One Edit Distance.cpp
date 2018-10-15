class Solution {
    // 思路: 從短的數列下手去搜, 所以一開始先確定s會是短的那個
    // 情況分成 長度差 > 1, =1, =0 來處理
    // 一有修正的動作就跳出loop判斷結果
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m > n) return isOneEditDistance(t,s);
        if(n-m>1) return false;
        bool corrected = false;
        for(int i=0;i<m;i++) {
            if(s[i]!=t[i]) {
                if(m==n) {
                    s[i] = t[i];
                } else {
                    s.insert(i,1,t[i]);
                }
                corrected = true;
                break;
            }
        }
        // 第一個判斷比較 tricky, 原本只寫!corrected, 想說都沒不一樣的就ok
        // 後來才想到題目規定一定要edit distance = 1, 也就是前面m個全部都一樣的話反而不OK, 要在長度上做出差距才行
        // 第二個就單純看修正後是不是一樣的
        return (!corrected && n-m==1) || (corrected && s==t);
    }
};