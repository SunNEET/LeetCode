class Solution {
    /*
        letter logs 和 digital logs 分開處理
        letter logs 要先用第二個 word 來比較, 字典序小的放前面(a<b)
        一樣的時候就用第一個 word 的字典序比
        然後把digital logs原封不動插到llogs後面

        value	relation between compared string and comparing string
        0	They compare equal
        <0	Either the value of the first character 
        that does not match is lower in the compared string, 
        or all compared characters match but the compared string is shorter.
        >0	Either the value of the first character 
        that does not match is greater in the compared string, 
        or all compared characters match but the compared string is longer.
    */ 
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> llogs, dlogs;
        for(auto log : logs) {
            string ss = log.substr(log.find(' ')+1); // get the word after the id
            if(isalpha(ss[0])) llogs.push_back(log);
            else dlogs.push_back(log);
        }
        sort(llogs.begin(), llogs.end(), [](const string& a, const string& b){
            string sa = a.substr(a.find(' ')+1);
            string sb = b.substr(b.find(' ')+1);
            if(sa == sb) return a < b;
            return sa < sb;
        });
        llogs.insert(llogs.end(), dlogs.begin(), dlogs.end());
        return llogs;
    }
};