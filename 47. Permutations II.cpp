class Solution {
    // 採用上一題方法的延伸, 加入sort和連續同value的判斷
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> visited;
        int len = (int)nums.size();
        if(!len) return {};
        visited.resize(len);
        visited.clear();
        // 關鍵點1, 透過排序能將同樣的數字連在一起
        // 這樣等下就可以透過一些判斷避免枚舉到重複的元素
        std::sort(nums.begin(), nums.end());
        dfs(0, tmp, nums, res, visited);
        return res;
    }
    void dfs(int pos, 
             vector<int> &tmp, 
             vector<int> &nums, 
             vector<vector<int>> &res,
             vector<bool>& visited) {
        if(pos == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<(int)nums.size();i++) {
            // 關鍵點2, 要避免枚舉出相同組合的情況
            // 就是出現連續相同數字時, 如果現在是前一個數字沒有用到的情況
            // 那這個數就選擇直接跳過, 這樣就可以避免把前面那個數字所做的組合又通通枚舉一遍
            
            // 比方說[1,1,2,3,5]會先做過一次遍歷順序為i=0,1,2,3,4的
            // [1,1,2,3,5], 在[1~4]的組合都做完後,
            // 先選i=1, 如果照正常枚舉, 這時候選到i=0, 因為是一樣的value
            // 順著做下去就會做出跟剛剛一模一樣的組合, 這樣就不合要求
            // 所以遇到"跟前一個值一樣的數"且"前一個值沒用到的情況"
            // 就跳過不枚舉
            // 畢竟連續同value枚舉的情況一定第一次時就做過了
            
            if (i>0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            if(!visited[i]){
                tmp.push_back(nums[i]);
                visited[i] = true;
                dfs(pos+1,tmp,nums,res,visited);
                tmp.pop_back();
                visited[i] = false;
            }
        }
        
    }
};