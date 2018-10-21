class ValidWordAbbr {
// 題目解讀有坑, 簡單的說, 每個字典裡的字都一律縮寫成只保留頭尾, 中間變數字
// 規則解讀
// (1)isUnique("apple"): 假如apple沒在字典裡出現過, a3e也沒出現過 -> unique
// (2)isUnique("deer"): 假如deer在字典出現過n次, 而且只有他會縮寫成d2r -> unique

private:    
    unordered_map<string,int> dict_cnt;
    unordered_map<string,int> abbr_cnt;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(int i=0;i<(int)dictionary.size();i++) {
            dict_cnt[dictionary[i]]++;
            abbr_cnt[makeAbbr(dictionary[i])]++;          
        }
    }
    string makeAbbr(string s) {
        string res="";
        res += s[0] + to_string((int)s.length()-2) + s[(int)s.length()-1];
        return res;
    }
    
    bool isUnique(string word) {
        if(dict_cnt[word]!=abbr_cnt[makeAbbr(word)])
            return false;
        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */