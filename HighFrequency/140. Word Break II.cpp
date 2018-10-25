class Solution {
private:
    unordered_map<string,vector<string>> done;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 讓s1丟整個字串下去時，s2丟""就會回傳""，否則因為""沒得拆，他會回傳空的vector
        done[""].push_back("");
        return dfs(s, wordDict);
    }
    vector<string> dfs(string s, vector<string>& wordDict) {
        // 唯一的DP點，先前已經組合過的子字串就把他的結果回傳
        if(done.count(s)) 
            return done[s];
        // 枚舉所有的可能 把"abcdefg"從"a"+"bcdefg"枚舉到"abcdefg" + ""為止
        // 過程中左邊的s1一有分解出字典裡有的字串，就把右邊的s2丟進dfs裡，看他能分解出什麼花樣
        // 如果分解不出東西，ans就會回傳一個空的vector(不是空字串!)，因此也沒有辦法push答案
        vector<string> ans;
        for(int len=1;len<=s.length();len++) {
            string s1 = s.substr(0,len);
            string s2 = s.substr(len);
            if(count(wordDict.begin(),wordDict.end(),s1)!=0) {
                vector<string> s2_com = dfs(s2,wordDict);
                for(string el : s2_com) {
                    if(el=="") { // s1已經選到整個s了，所以s2下去dfs回來只會是""(透過一開始的setting)
                        ans.push_back(s1);    
                    } else {
                        ans.push_back(s1+" "+el);
                    }
                }
            }
        }
        // 把這次s分解嘗試的組合存到map，如果拆不出東西就會是空的
        done[s]=ans;
        return ans;
    }
};