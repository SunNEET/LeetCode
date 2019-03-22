class Solution {
    /*
        用一個hashmap來記錄出現過的數字和他的freq
        再掃一次hashmap來找出有沒有num+k存在
        注意只找num+k可以確保我們不會輸出重複的情況
        k=0跟k!=0要特別分開處理
        Time:  O(N)
        Space: O(N)
    */
public:
    int findPairs(vector<int>& nums, int k) {
        if(!nums.size() || k < 0) return 0;
        unordered_map<int,int> exists;
        int count = 0;
        for(int i=0; i<nums.size(); i++) exists[nums[i]]++;
        for(auto entry : exists) {
            int num = entry.first, freq = entry.second;
            if (!k && freq >= 2) {
                count++;
            }
            else if (k && exists.count(num+k)) count++;
        }
        return count;
    }
};


