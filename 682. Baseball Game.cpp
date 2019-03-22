class Solution {
    /*
        vector 加 模擬操作
    */
public:
    int calPoints(vector<string>& ops) {
        vector<int> nums;
        for(auto& op : ops) {
            int sz = nums.size();
            if(op == "C") nums.pop_back();
            else if(op == "D") nums.push_back(2*nums.back());
            else if(op == "+") nums.push_back(nums[sz-1] + nums[sz-2]);
            else nums.push_back(stoi(op));
        }
        int sum = 0;
        for(auto& num : nums) sum += num;
        return sum;
    }
};
