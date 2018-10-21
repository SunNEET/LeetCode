class Solution {
    // 用unordered_set來處理, 省略重複的情況
    // 枚舉每個元素的時候同時往前往後找, 如果有找到元素+-1就把next++或prev--, 找到不滿足為止
    // 然後用 next - prev + 1 求出這個子序列的長段
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        int ans = 0;
        for(int i=0;i<nums.size();i++) 
            hash.insert(nums[i]);            
        
        for(int i=0;i<nums.size();i++) {
            int cur = nums[i];
            if(!hash.count(cur)) continue;
            int next = cur+1;
            int prev = cur-1;
            hash.erase(cur);
            while(hash.count(next)){
                hash.erase(next);
                next++;
            } 
            while(hash.count(prev)) {
                hash.erase(prev);
                prev--;
            }
            ans = max(ans, (next-1)-(prev+1)+1);
        }
        return ans;
    }
};