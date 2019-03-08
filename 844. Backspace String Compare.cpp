class Solution {
    /*
        直覺解法，從字串後面掃回來產生最後的字串，遇到 # 就 increment counter
        當 counter 不是 0 就忽略當前的字元
    */
public:
    bool backspaceCompare(string S, string T) {
        string nS = "", nT = "";
        int bk_cnt = 0;
        for(int i = S.length()-1; i >= 0; i--) {
            if(S[i] == '#') bk_cnt++;
            else if (bk_cnt) bk_cnt--;
            else nS += S[i];
        }
        bk_cnt = 0;
        for(int i = T.length()-1; i >= 0; i--) {
            if(T[i] == '#') bk_cnt++;
            else if (bk_cnt) bk_cnt--;
            else nT += T[i];
        }
        return nS == nT;
    }
};

class Solution {
    /*
        不用 extra space 的做法，一次處理T或S的一個字元，直到他們目前
        idx指向的都是有效的字元，再讓他們進行比較

        幾個坑點：
        (1) 判斷字元是否為 # 前，idx 也要判斷是否 >= 0，
            因為他可能已經刪除到 idx 超過 0 了
            
        (2) 當其中一邊的 idx 已經 < 0 (刪光了)，而另一邊還 >=0 (還有剩)
            要回傳 false，如果兩邊都刪光了就會跳出 while 迴圈，所以不用擔
            心接下來的字元比較會出問題
    
    */
public:
    bool backspaceCompare(string S, string T) {
        int s_idx = S.length() - 1, t_idx = T.length() - 1;
        int s_bkcnt = 0, t_bkcnt = 0;
        while(s_idx >= 0 || t_idx >= 0) {
            if(s_idx >= 0 && S[s_idx] == '#') {
                s_bkcnt++;
                s_idx--;
                continue;
            } else if(s_bkcnt) {
                s_bkcnt--;
                s_idx--;
                continue;
            }
            if(t_idx >=0 && T[t_idx] == '#') {
                t_bkcnt++;
                t_idx--;
                continue;
            } else if(t_bkcnt) {
                t_bkcnt--;
                t_idx--;
                continue;
            }
            if((s_idx < 0 && t_idx >= 0) || (s_idx >= 0 && t_idx < 0)) {
                return false;
            } else if(S[s_idx] != T[t_idx]) {
                return false;
            } else {
                s_idx--;
                t_idx--;
            }
        }
        return true;
    }
};

