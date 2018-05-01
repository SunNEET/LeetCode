class Solution {
// 忘了可以直接用ans求上一列，不用另外再存個pre。
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> cur;
        for(int i=0;i<numRows;i++) {
            cur.clear();
            for(int j=0;j<i+1;j++) {
                if (j==0 || j==i) {
                    cur.push_back(1);
                } else {
                    cur.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};