class Codec {
    // encode: 把每個字串前面加上 字串長度 + "/"
    // decode: find "/", 把前面的部分切出來, 也就是長度, 然後根據長度把 "/" 後面用substr取出來
    // 新的 index = "/" 的位置 + substr長度 + 1 
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i=0;i<strs.size();i++) {
            res += to_string(strs[i].length()) + "/" + strs[i];
        }
        cout << res << endl;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int index = 0;
        vector<string> res;
        while(index < s.length()) {
            int slash = s.find("/",index);
            int len = atoi(s.substr(index,slash-index).c_str());
            res.push_back(s.substr(slash+1,len));
            index = slash+len+1;
        }

        return res;
    }
};
