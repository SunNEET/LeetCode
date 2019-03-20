class Solution {
    /*
        Greedy, 考量三個變數 reach, step 和 maxposition
        reach 代表目前能到的最右界
        step  表示擴展到這個reach要走了步
        maxposition 表示下一次的step能走到的最右界
    */
public:
    int jump(vector<int>& nums) {
        if(!nums.size()) return 0;
        int reach = 0, step = 0, max_position = 0;
        for(int i=0; i<nums.size()-1; i++) {
            max_position = max(max_position, i+nums[i]);
            if(i == reach) {
                reach = max_position;
                step++;
            }
        }
        return step;
    }
};