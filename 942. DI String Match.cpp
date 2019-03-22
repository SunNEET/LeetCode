class Solution {
    /*
        Two Pointer, 遇到D就填目前最大的, 遇到I就填目前最小的
    */
public:
    vector<int> diStringMatch(string S) {
        int min_num = 0, max_num = S.length();
        vector<int> res;
        for(char ch : S) {
            if(ch == 'I') {
                res.push_back(min_num++);
            } else {
                res.push_back(max_num--);
            }
        }
        res.push_back(min_num);
        return res;
    }
};