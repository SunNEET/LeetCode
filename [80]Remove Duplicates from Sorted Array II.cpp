class Solution {
// 跟I的做法類似，只是要多用一個cnt紀錄重複的次數
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        
        int cnt = 0;
        int j = 0;
        // i需要直接從第二個開始做，第一個直接保留給答案，這樣第一個if裡的邏輯順序才不會出現bug i.e nums[1] := nums[0]
        for(int i=1;(int)i<nums.size();i++) {
            if (nums[i] == nums[j]) {
                cnt++;
                //同一個數可以重複出現一次
                if (cnt < 2) {
                    nums[++j] = nums[i];
                }
            } else {
                nums[++j] = nums[i];
                cnt = 0;
            }
        }
        return j+1;
    }
};