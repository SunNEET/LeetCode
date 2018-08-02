class Solution {
    // 假如有兩個長度相同的字串a跟b, 要判斷a是不是b的一種排列的方式
    // 其實就是看他們裡面字母的出現次數有沒有一樣就好
    // 要套用在這題的話
    // 就是用一個長度跟a一樣的sliding window來看b
    // 當sliding window裡字母的出現次數跟a一樣那就是上面說的狀況了
    
    // 那問題的重點就在 怎麼數sliding window裡的字母
    // 我們先令cnt是s1裡, 字母的出現次數
    // 然後每當有字母進入window範圍的時候, 就把該字母的次數-1
    // 當有字母離開範圍的時候, 就把該字母的次數+1回去
    
    // 而當window內出現cnt的字母都等於0的情況
    // 表示這個window就是s1的排列了
    
    // *初始化window的時候, 就相當於s2開頭的那幾個長s1的字母一口氣進入window
    // 所以直接把他們都-1
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26,0);
        int len1 = s1.length();
        for(int i=0;i<len1;i++) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        // 一開始的window就找到答案的情況
        if(isAllZero(cnt)) return true;
        
        // 開始往右移動
        int len2 = s2.length();
        for(int i=len1,j=0;i<len2;) {
            cnt[s2[i++]-'a']--;
            cnt[s2[j++]-'a']++;
            if(isAllZero(cnt)) return true;
        }
        return false;
    }
    
    bool isAllZero(vector<int>& cnt) {
        for(int i=0;i<26;i++)
            if(cnt[i]!=0)
                return false;
        return true;
    }
};