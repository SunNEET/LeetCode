class Solution {
    /*
        模擬: 用一個idx當runner, 另一個ans_idx負責填答案,
        每一輪新開始就是看後面有多少個重複的, count超過1就要壓縮
        
    */
public:
    int compress(vector<char>& chars) {
        int ans_idx = 0, idx = 0;
        while(idx < chars.size()) {
            char cur_char = chars[idx];
            int count = 0;
            while(idx < chars.size() && chars[idx] == cur_char){
                idx++;
                count++;
            }
            chars[ans_idx++] = cur_char;
            if(count != 1) { // one single char no need to do compress
                string cnt_str = to_string(count);
                for(char c : cnt_str)
                    chars[ans_idx++] = c;
            }
        }
        return ans_idx;
    }
};

