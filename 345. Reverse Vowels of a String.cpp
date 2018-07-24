class Solution {
    // reverse 其實就是從左右兩側一直做頭尾互換
    // 所以這題就從兩側找母音, 同時移動兩個it, 兩邊都找到了就swap
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length()-1;
        while(l<r) {
            // 不是母音, 就一直移動
            while(!isVowel(s[l])) 
                l++;
            while(!isVowel(s[r])) 
                r--;
            // 有可能進外層while前l<r, 但中間找不到別的母音
            // 一直l++,r--, 最後就l>r了
            // 這樣會造成前面換過的又被換回來, 必須避免
            if(l<r)
                std::swap(s[l++],s[r--]);
        }
        return s;
    }
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
};