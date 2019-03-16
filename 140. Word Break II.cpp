class Solution {
    /*
        s = "catsanddog"
        wordDict = ["cat", "cats", "and", "sand", "dog"]
        enumerate length [0 ~ s.length-1] to split the string s to generate two substring
        
        len = 0 -> s1 = "", s2 = "catsanddog"
        len = 1 -> s1 = "c", s2 = "atsanddog"
        ...
        if s1 is a word in dict, then see how s2 can get splitted
        
        s1 = "cat", s2 = "anddog"                                    (6)====> s = s1 + s'
        (1)====> s'="anddog", s1' = "and", s2' = "dog"               (5)====> s' is consists s1' + s''
        (2)====> s''="dog", s1'' = "dog", s2'' = "" << base case     (4)====> s'' is consist of s1'' + s'''
        (3)====> s''' = "" return  ""
        During the process (1)~(3), it's likely to exists more than one substring s1
        so we should put every combination of s into a vector and then return it.
        
        To speed up, we can use a map to record a string and how it can be break up
        
        Time:  O(N*L), L is the lenght of s, N is the size of dict
        Space: O(N)
    */
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> DP;
        return DFS(s, dict, DP);
    }
private:
    vector<string> DFS(const string& s, unordered_set<string>& dict, unordered_map<string, vector<string>>& DP) {
        if(DP.count(s)) return DP[s];
        if(s=="") return vector<string>({""});
        vector<string> res;
        for(int len=1; len<=s.length(); len++) {
            string s1 = s.substr(0, len);
            string s2 = s.substr(len);
            if(dict.count(s1)) {
                vector<string> s2_brk = DFS(s2, dict, DP);
                for(auto word : s2_brk) {
                    if(word == "") res.push_back(s1); // s1 is the last word
                    else res.push_back(s1+" "+word);
                }
            }
        }
        DP[s] = res;
        return res;
    }
};