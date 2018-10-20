class Solution {
    // 用deque做monotonicQueue, 對於window內的元素, 如果"新進來"的比"原本的"元素大
    // 就把那些元素都pop掉, 因為接下來的區間內他們也不會成為maxValue
    // 新進來的如果比原本小就直接留著, 因為原本的max元素pop掉後他們可能就成為區間內的maxValue了
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> window;
        for(int i=0;i<nums.size();i++) {
            while(!window.empty() && nums[i] > window.back()) window.pop_back();
            window.push_back(nums[i]);
            if(i-k+1>=0) {
                ans.push_back(window.front());
                // 判斷要不要pop掉window前頭元素的方式比較tricky
                // 如果遇到n[i-k+1], 也就是最前頭就是maxValue的情況, 那他下個window就會不見了, 所以要pop掉
                // 不是上面的情況表示有其他元素比n[i-k+1]大, 所以早在之前push就已經拿掉了
                if(nums[i-k+1] == window.front())
                    window.pop_front();
            }            
        }
        return ans;
    }
};