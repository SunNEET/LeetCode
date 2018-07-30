#define MAX_STEP 6 
class Solution {
    // 這題目前有瑕疵 LC上的標程本身就是錯的...沒什麼參考價值
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end()); 
        int res = helper(board, hand); 
        return res > hand.size() ? -1 : res;
    }
    
    int helper(string b, string h) {
        if (b.empty()) return 0;
        if (h.empty()) return MAX_STEP;
        int res = MAX_STEP;
        for (int i = 0; i < h.size(); i++) {
            int j = 0;
            int n = b.size();
            while (j < n) {
                int k = b.find(h[i], j);
                if (k == string::npos) break;
                if (k < n-1 && b[k] == b[k+1]) { // 2 consecutive balls with same color on board
                    string nextb = shrink(b.substr(0, k) + b.substr(k+2)); // shrink the string until no 3 or more consecutive balls in same color
                    if (nextb.empty()) return 1; // this is the best result for current board, no need to continue
                    string nexth = h;
                    nexth.erase(i, 1); // remove the used ball from hand
                    res = min(res, helper(nextb, nexth) + 1);
                    k++;
                }
                else if (i > 0 && h[i] == h[i-1]) { // 2 balls with same color in hand
                    string nextb = shrink(b.substr(0, k) + b.substr(k+1)); // shrink the string until no 3 or more consecutive balls in same color
                    if (nextb.empty()) return 2;  // this is the best result for current board, no need to continue
                    string nexth = h;
                    nexth.erase(i, 1); // remove the used balls from hand
                    nexth.erase(i-1, 1);
                    res = min(res, helper(nextb, nexth) + 2);
                }
                j = k + 1;
            }
        }
        return res;
    }
    
    string shrink(string s) {
        while(s.size() > 0) {
            int start = 0;
            bool done = true;
            for (int i = 0; i <= s.size(); i++) {
                if (i == s.size() || s[i] != s[start]) {
                    if (i - start >= 3) {
                        s = s.substr(0, start) + s.substr(i);
                        done = false;
                        break;
                    }
                    start = i;
                }
            }
            if (done) break;
        }
        return s;
    }
};