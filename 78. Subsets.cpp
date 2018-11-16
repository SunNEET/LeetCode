class Solution {
    /*
        由於題目給的數組是 distinct numbers，所以依序枚舉並不會出現重複。
        枚舉可以用 DFS 來做。

        Time complexity: O(n*2^n)，每次都在判斷 take or not take，所以會有2個分歧，長度為n，所以葉子會是2^n個。
        但中間的節點也要算上去，因為並非“每个叶节点是一个解”，而是“每个节点是一个解”
        所以實際上會是 n*2^n
                                Start state
                               /          \
                              /            \
                             /              \
                          T-1                DT-1
                         /   \               /   \
                        /     \             /     \
                       /       \           /       \
                      /         \         /         \
                     T-3      DT-3      T-3         DT-3
                    / \        /  \      / \         /  \
                   /   \      /    \    /   \       /    \
                  T-5  DT-5 T-5  DT-5  T-5  DT-5   T-5   DT-5

        Space complexity: O(n)
    */
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> sub;
        DFS(nums,res, sub, 0);
        return res;
    }
    void DFS(const vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int start) {
        res.push_back(sub);
        for(int i=start;i<(int)nums.size();i++) {
            sub.push_back(nums[i]);
            DFS(nums,res,sub,i+1);
            sub.pop_back();
        }
    }
};