class Solution {
    // 跟前一題的觀念差不多，排序完以後，先枚舉一個a[i]
    // 再配合j,k縮小範圍找出最適當的值
    // 只是這題是找靠最近的target的sum是多少
    // 不像上一題找到解才維護答案，這邊要一直維護目前最短的dis
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int dis = INT_MAX;
        int ans = 0;
        for(int i=0; i<nums.size();i++) {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k) {
                int tmp_val = nums[i]+nums[j]+nums[k];
                int tmp_dis;
                //比目標小,遞增j
                if(tmp_val < target) {
                    tmp_dis = target - tmp_val;
                    if(tmp_dis < dis) {
                        dis = tmp_dis;
                        ans = tmp_val;
                    }
                    j++;
                }
                //比目標大,遞減k
                else if(tmp_val > target) {
                    tmp_dis = tmp_val - target;
                    if(tmp_dis < dis) {
                        dis = tmp_dis;
                        ans = tmp_val;
                    }
                    k--;
                }
                // 等於目標, 就是答案
                else {
                    ans = tmp_val;
                    return ans;
                }
            }
        }
        return ans;
    }
};