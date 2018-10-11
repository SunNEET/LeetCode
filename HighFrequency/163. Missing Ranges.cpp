class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        // edge case: 空nums，但還是要返回lower跟upper之間的missing range
        if(nums.size()==0){
            addRange(ans, lower, upper);
            return ans;
        
        // edge case2: 測資會有INT_MIN,跟INT_MAX 所以+-1會爆掉, 要轉成 long long int
        // 考慮 lower 到 nums 起點的missing情況
        addRange(ans, lower, (long long int)nums[0]-1);
        
        // nums 中的missing情況
        for(int i=1;i<nums.size();i++) {
            addRange(ans, (long long int)nums[i-1]+1, (long long int)nums[i]-1);
        }
                
        // 考慮 nums 結尾到 upper 的missing情況
        addRange(ans, (long long int)nums[nums.size()-1]+1, upper);
        return ans;
    }
    
    void addRange(vector<string>& ans, long long int s, long long int e) {
        // lower 比 nums 起點高 or nums 結尾超過upper or nums中s跟e是兩個連續整數，s+1,e-1就會導致s>e
        if(s > e) 
            return;
        // nums 中 s 跟 e 剛好中間差一個數字，所以 s+1 == e-1
        if(s == e) {
            ans.push_back(to_string(s));
            return;
        }
        ans.push_back(to_string(s) + "->" + to_string(e));
    }
};