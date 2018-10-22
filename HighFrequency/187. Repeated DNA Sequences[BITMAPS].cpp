class Solution {
    // 考慮到用substring做Hash, 可能會佔用太多記憶體, 如果測資變大了就會炸掉
    // 改成將字元ACGT看成bits, 湊成一個30bits的資料, 這樣就可以用一個int來存了
    // 關鍵: (1) ACGT的bits => A is 0101, C is 0103, G is 0107, T is 0124
    // (2) 由上所知, 我們只要取後3個bits(透過&7{0111})就好, 十個字母就是30bits
    // (3) 組字串的bits就是一直把當前的往左移3bits挪出空間, 然後 | 新的3bits上去
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> hash;
        vector<string> ans;
        int cur = 0;
        for(int i=0;i<9;i++)
            cur = cur<<3 | s[i]&7;
        for(int i=9;i<s.length();i++) {
            // 把超過30bits的部分忽略掉, 用mask 0x3fffffff
            cur = cur<<3 & 0x3fffffff | s[i]&7;
            // 因為只塞一次, 所以只判斷==1而不是>=1
            if(hash[cur]++ == 1)
                ans.push_back(s.substr(i-9,10));
        }
        return ans;
    }
};