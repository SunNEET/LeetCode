class Solution {
    /*
        一直update現在能到最遠的是哪裡(reach)
        在pos還沒cross goal和cross reach之前就一直重複
        回傳值判斷是否 reach >= goal
    */
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        int pos = 0, reach = 0;
        for (; pos < goal && pos <= reach; pos++)
            reach = max(reach, pos+nums[pos]);
        return reach >= goal;
    }
};