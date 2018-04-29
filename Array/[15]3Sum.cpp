class Solution {
    // 跟前一題2sum是類似的作法，先枚舉一個數字，再直接去找能滿足的情況
    // 這題就是直接找j+k = -i，所以用two pointer表示j跟k
    // 從前後開始往內找是因為有排序過以後，可以保證a[j+1]>=a[j]而a[k-1]<=a[k]
    // 因此，當我們找出來的a[i]+a[j]+a[k]的值<0的話，就去遞增j，可以保證sum增加/不變
    // 反之就遞減k，保證sum變小/不變，以此來逼近0，就能在O(n)內找出有可能的j+k組合。
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        if(nums.size()<=2) return ans;
        std::sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-2;i++) {
            int j = i+1;
            int k = nums.size()-1;
            while(j < k) {
                if(nums[i]+nums[j]+nums[k] == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
                    j++; k--;
                    //調過重複的答案，因為排序過了，遞增遞減直到不是重複的a[j]或a[k]就好
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                } else if(nums[i]+nums[j]+nums[k] < 0) { 
                    j++;
                } else {
                    k--;
                }
            }
            //如果下個枚舉的還是一樣的數，就跳過
            while(i<nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};