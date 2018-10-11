class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // 用 two pointers 來做
        // i == j 就一起+1, j如果是指到數字就往後找到不是數字為止, 然後用substr把他截出來再用atoi轉成數字加到i上
        // 如果i跳太多或太少就會在下個loop知道了
        int i=0,j=0;
        while(i<word.length() && j<abbr.length()) {
            if (word[i] == abbr[j]){
                i++;
                j++;
            } else if((abbr[j]>'0') && (abbr[j]<='9')) {
                int s = j++;
                int len = 1;
                while(j < abbr.length() && (abbr[j]>='0') && (abbr[j]<='9')) {
                    j++;
                    len++;
                }
                i += atoi(abbr.substr(s,len).c_str());
            } else {
                return false;
            }
        }
        return (i == word.length()) && (j == abbr.length());
    }
};