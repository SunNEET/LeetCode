class Solution {
    // 用"\n"分割字串(沒有內建split, 所以我就邊掃邊substr)
    // 用"\t"的數量來判斷他的層數
    // 把分割出來的字串想成從上往下一行一行讀，把前面字串的長度都記下來存，map到層數。
    // 當\t變少的時候代表已經離開上面的路徑了，所以直接把新的路徑長度蓋到map上就可以了。
public:
    int lengthLongestPath(string input) {
        unordered_map<int,int> dirLen;
        dirLen[0] = 0;
        int cur=0, ans=0, flag=0;
        string s;
        for(int i=0;i<input.length();i++) {
            // 到\n or 盡頭會是一個字串
            if(input[i]=='\n') {
                s = input.substr(cur, i-cur);
                cur = i+1;
                flag = 1;
            } else if(i==input.length()-1) {
                s = input.substr(cur, i-cur+1);
                flag = 1;
            }
            if(flag){
                // 判斷這個字串的層數(\t數量)
                // 為了要方便下面統一用lvl-1來累加長度
                // 所以把lvl通通往上挪, 沒有\t的第一列當作第一層
                // 沒有 /t 的上到第一層, 有 /t 的就是從第二層開始數
                // 有\t的則是 \t的last index+1(ps+1)
                size_t ps = s.find_last_of('\t');
                int lvl = (ps!=std::string::npos) ? 2+ps : 1;
                int len = s.length()-lvl+1;
                if(s.find('.')!=std::string::npos) {
                    ans = max(ans, dirLen[lvl-1] + len);
                } else {
                    dirLen[lvl] = dirLen[lvl-1] + len + 1; // 前面的資料夾長度 + 自己的名稱長度 + "/"
                }
                flag = 0;
            }
        }
        return ans;
    }
};