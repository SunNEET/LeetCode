class Solution {
    /*
        極限複雜的一題，用遞歸求解，s 和 p 一邊比較一邊往右移動。
        各種條件：
        p.length == 0 (終止條件)，p 已經移到底(空了)時判斷 s 是否也同時到底了(空了)。 - (1)
        
        p.length == 1 
        如果 S 已經空了，就 return false。 - (2)
        不然的話繼續比較兩邊的唯一一個字元，往遞迴丟下去。 - (3)
            - if (p[0] == s[0] || p[0] == '.')
                isMatch(s.substr(1), p.substr(1))
            - else return false
            
        p.length >= 2 最 general 也最複雜的情況，要考慮 * 的問題 
        
        if(p[1]!='*')，當p的第二個字符不是星號時，問題很單純，判斷能不能往下遞歸就好。 - (4)
            - if S不空 && (p[0] == s[0] || p[0] == '.')
                則進入下一層遞歸，isMatch(s.substr(1), p.substr(1))
            - else return false

        if(p[1]=='*' )，當p的第二個字符是星號且
            - if S不空 && (p[0] == s[0] || p[0] == '.')，有兩種分支需要分別判斷： - (5)
                (分枝ㄧ)某字符+星號"不要匹配"s的首字符：（因為星號之前的字符可出現可不出現，該情況不配是考慮到後面有必須匹配的。假設當前匹配並截去s的首字符，會導致後續匹配錯誤。）
                         截去p的前兩個元素（某字符+星號）並進入下一層遞歸，
                         假如返回true，則當前遞歸返回true
                         假如返回false，進入分支2。
                (分枝二)某字符+星号"要匹配"s的首字符：
                         截去s首字符并继续条件5的判断。
            - else 雖然p[1]是星號但 S 可能空了 
                或是原本就找不到匹配的(p[0] != s[0] 而且 p[0] != '.') - (6)
                         直接忽略字母+*往下歸遞
                
        Time complexity: O((|s|+|p|)*2^(|s|+|p|))        
    
        Clarify:
        (1) Can s and p be empty?
        (2) Will they contain some other characters? I mean  some characters other than letters, dots and stars.
    */
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        // (2) (3) (4) 裡面的判斷一樣，所以寫在一起
        if(p.length() == 1 || p[1] != '*') {
            if(s.empty() || (p[0]!= '.' && p[0]!=s[0]))
                return false;
            else
                return isMatch(s.substr(1), p.substr(1));
        }
        
        // 會到這裡表示 p[1] 是星號 且p長度 >= 2
        while(!s.empty() && ( p[0]=='.' || s[0]==p[0] )) {
            if(isMatch(s, p.substr(2)))
                return true;
            s = s.substr(1);
        }
        // 跳過不吻合的 p[0] 和 星號
        return isMatch(s, p.substr(2));
    }
};