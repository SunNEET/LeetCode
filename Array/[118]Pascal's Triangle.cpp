class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> pre;
        vector<int> cur;
        for(int i=0;i<numRows;i++) {
            cur.clear();
            for(int j=0;j<i+1;j++) {
                if (j==0 || j==i) {
                    cur.push_back(1);
                } else {
                    cur.push_back(pre[j-1]+pre[j]);
                }
            }
            pre = cur;
            ans.push_back(cur);
        }
        return ans;
    }
};