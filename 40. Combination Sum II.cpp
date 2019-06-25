class Solution {
    /*
        基本上跟前一題一樣，DFS 枚舉
        然後枚舉 array 元素同時處理重複都是那一招
        sort + [!start]遇到一樣的value ([!start-1])就直接跳過
        
        Time:  O(2^N)
        Space: O(N)
    */
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        if(!candidates.size()) return res;
        DFS(res, candidates, tmp, target, 0, 0);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, const vector<int>& candidates, vector<int>& tmp,
             const int& target, int start, int sum) {
        if(sum > target) return;
        if(sum == target) {
            res.push_back(tmp);
            return;
        }
        for(int i = start; i<candidates.size(); i++) {
            if(i != start && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            DFS(res, candidates, tmp, target, i+1, sum + candidates[i]);
            tmp.pop_back();
        }
    }
};