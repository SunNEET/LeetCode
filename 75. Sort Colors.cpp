class Solution {
    // 用 counting sort 的思路，統計0,1,2出現了幾次，然後由後往前填就好了
    // Time complexity: O(N)
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) red++;
            if(nums[i]==1) white++;
            if(nums[i]==2) blue++;
        }
        for(int i=(int)nums.size()-1;i>=0;i--) {
            if(--blue>=0)
                nums[i] = 2;
            else if(--white>=0)
                nums[i] = 1;
            else if(--red>=0)
                nums[i] = 0;
        }
    }
};

class Solution {
    // Follow up: 1 pass 的作法
    // 因為總共就只會有三種數0,1,2，而0必定是從前面開始排，2必定是從後面開始排，
    // 所以可以用 Three pointer 來處理。用 low 指向目前0該填入的位置(從 beginning 開始+1)，
    // high 指向 2 該填入的位置(從 ending 開始-1)，再用一個 curIdx 來負責掃 nums。
    // 所以遇到 0 就往 low 放，遇到 2 就往 high 放，然後減縮 low 跟 high 的 range，
    // 直到 curIdx > high 就跳出。
    
    // Key point: 
    // 如果 curIdx 掃到的是 1，那就先保留他的位置，把 curIdx++ 繼續往後看
    // 如果現在指向的是 0，就把他跟 low 指向的位置 swap，相當於把這個 0 填到 low 然後 low++, curIdx++。
    // swap完後 curIdx 可以直接+1是因為按照我的swap規則的話，掃到當前這個 0 時，low 現在會指的只會是 1
    // 所以換完後就繼續 move。
    // 如果指向 2，就把它跟 high 指向的 swap，然後 high--，注意這裡不能直接 curIdx++，
    // 因為無法確定他是 0 還是 1。

public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = (int)nums.size()-1;
        int curIdx = 0;
        while(curIdx <= high) {
            if(nums[curIdx] == 0) {
                swap(nums[curIdx], nums[low]);
                low++;
                curIdx++;
            } else if(nums[curIdx] == 2) {
                swap(nums[curIdx], nums[high]);
                high--;
            } else { // 1
                curIdx++;
            }
        }
    }
};