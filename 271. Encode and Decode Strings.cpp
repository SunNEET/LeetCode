class Codec {
    /*
      encode: 把每個字串前面加上 字串長度 + "/"
      坑點：字串長度要記得用 to_string 轉換
     
      decode: 維護一個目前指向的index
      用find "/", 把前面的部分切出來, 也就是長度, 然後根據長度把 "/" 後面用substr取出來
      新的 index = "/" 的位置 + substr長度 + 1 

      Time: O(N)  for encode(), where N is the size of strs, 
            O(NM) for decode(), where M is the longest length of the string in strs.
    
    */
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i=0; i<strs.size(); i++) {
            res += to_string(strs[i].length()) + "/" + strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int idx = 0;
        while(idx < s.length()) {
            int slash = s.find("/",idx);
            int len = atoi(s.substr(idx,slash).c_str());
            res.push_back(s.substr(slash+1,len));
            idx = slash+len+1;
        }
        return res;
    }
};
