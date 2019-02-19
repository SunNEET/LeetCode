class Solution {
    /*
        用 hashMap 紀錄 for 到目前為止掃過的數字，
        然後每次有新數字都去看hashmap裡有沒有 target-nums[i] 的數字存在
        
        To solve it in O(N) time complexity, we can use a hashmap to record
        what values we've traverse, and then check if target-nums[i] exists in the 
        hashmap. If so, that means we find an answer as target-nums[i] plus nums[s] 
        equals to target.

        Two pointer + hashMap
        Time complexity: O(N)
        Space: O(N)
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

class Solution {
    /*
        不用 Hashmap 的做法，但複雜度會上升到 O(nlogn)
    */
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp(nums);
        int left = 0, right = nums.size()-1;
        sort(tmp.begin(), tmp.end());
        while(left < right) {
            int sum = tmp[left]+tmp[right];
            if(sum > target) right--;
            else if(sum < target) left++;
            else break;
        }
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == tmp[left] || nums[i] == tmp[right])
                ans.push_back(i);
        }
        return ans;
    }
};