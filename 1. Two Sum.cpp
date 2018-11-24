class Solution {
    /*
        Two pointer + hashMap
        Time complexity: O(N)
    */
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> res;
        for(int i=0; i<(int)nums.size(); i++) {
            if(hash.count(target-nums[i]))
                return vector<int>({hash[target-nums[i]],i});
            hash[nums[i]] = i;
        }
    }
};