class Solution {
    // 枚舉h跟m的組合, 然後轉成bitset, 再檢查1的數量是不是等於num
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                // 建立 10 bits的set, 並用int值初始化
                // 這個int值是巧妙的把 h左移6位,再跟m做OR操作來合成一個數
                // 用這個數字來初始化bitset
                if(bitset<10>(h<<6|m).count() == num)
                    ans.emplace_back(to_string(h)+(m < 10 ? ":0" : ":")+(to_string(m)));
            }
        }
        return ans;
    }
};