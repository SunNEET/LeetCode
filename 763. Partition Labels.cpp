class Solution {
    /*
        先掃過一遍，判斷每個字元出現的最後位置
        然後在重掃一次的時候，根據目前出現的最右位置更新 right bound
        如果 i 已經到 right bound 了，表示可以用i當做目前這個section的切割點
        
        其實跟mergeInterval的觀念有點像
    */
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> end_of;
        for(int i=0; i<S.length(); i++) end_of[S[i]] = i;
        vector<int> res;
        int left_bound = 0;
        int right_bound = 0;
        for(int i=0; i<S.length(); i++) {
            right_bound = max(right_bound, end_of[S[i]]);
            if(i == right_bound) {
                res.push_back(right_bound-left_bound+1);
                left_bound = right_bound+1;
            }
        }
        return res;
    }
};