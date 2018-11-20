class Solution {
    /*
        純考 reservoir sampling 的觀念，在不儲存他們出現位置的情況下，用同等的機率返回任意一個 target。
        當我們有很多選擇，但只能 keep 一個的時候，我們用機率決定是要保留當前 keep 的，還是換成新的。
        遇到第1個數n1的時候，我們保留它，p（n1）= 1
        遇到第2個數n2的時候，我們以1/2的機率保留它，p(n1) = 1*1/2，p(n2) = 1/2
        遇到第3個數n3的時候，我們以1/3的機率保留它，P(n1)=P(n2)=1/2*(1-1/3), p(n3)=1/3
        ...以此類推
    */
private:
    vector<int> nums;
public:
    Solution(vector<int> _nums):nums(_nums.begin(),_nums.end()) {
    }
    
    int pick(int target) {
        int cnt = 0;
        int res = -1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==target) {
                cnt++;
                if(rand()%cnt == 0)
                    res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */