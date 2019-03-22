class Solution {
    /*
        key: 從後往前找第一個遞增發生的位置(a[i]<a[i+1]), 然後跟後面那串大於a[i]中的最小值互換
        直接上其實不太好想到, 網路上找到一個例子還不錯
        有串array = [6,5,4,8,7,5,1]
        首先當然是從後面開始看, 但1跟5互換反而會變小
        8,7,5,1之間調換也沒有效果, 也都是越換越小, 此時也注意到8,7,5,1是遞減的
        如果想要找到下一個排列, 找到遞增的位置是關鍵
        因為在這裡才可以使其增長得更大
        於是找到了4, 顯而易見4過了是5而不是8或者7更不是1
        因此就需要找出比4大, 但在這些大數裡面最小的值, 並將其兩者調換
        那麼整個排列就成了：6 5 5 8 7 4 1
        這時還沒結束, 還要把5後面的那串遞減數列都變成遞增才行
        這樣才會是最小的情況
    */
public:
    void nextPermutation(vector<int>& nums) {
        int target_idx = nums.size()-1; 
        int greater_min_idx = nums.size()-1;
        while(target_idx > 0 && nums[target_idx-1] >= nums[target_idx]) 
            target_idx--;
        if(target_idx > 0) {
            target_idx--;
            while(nums[greater_min_idx]<=nums[target_idx]) 
                greater_min_idx--;
            swap(nums[greater_min_idx], nums[target_idx]);
        } else {
            target_idx = -1;
        }
        for(int left = target_idx+1, right = nums.size()-1; left < right; left++, right--)
            swap(nums[left], nums[right]);
    }
};