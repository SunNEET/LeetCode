class Solution {
    /*
        solution: 複習一下C++ stringstream 的做法，可以輕鬆切字串
        time complexity: 
        edge cases: 
        (1) 記得字元間要有空白，為了方便處理，統一加在前面，最後再substr拿掉就好
        (2) 要記得大小寫都要判斷 vowel，這邊用 tolower 代勞
    */
public:
    string toGoatLatin(string S) {
        string res = "", word = "";
        stringstream ss(S);
        unordered_set<char> vowel = {'a','e','i','o','u'};
        string extraA = "a";
        while(ss >> word) {
            if(vowel.count(tolower(word[0])))
                res += " " + word + "ma";
            else
                res += " " + word.substr(1) + word[0] + "ma";
            res += extraA;
            extraA += "a";
        }
        return res.substr(1); // skip white space
    }
};