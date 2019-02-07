class Solution {
    /*
        題意理解成 Find out the longest length of subarrays 
        with at most 2 different numbers
        Two pointer 做 sliding window，用 hash 紀錄水果出現次數，
        水果種類超過2種就開始 left++，直到有某種水果的數量已經歸0
        
        Time: O(N)
        Space: O(N)
    */
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> cnt;
        int res = 0, left = 0, right = 0;
        while(right < (int)tree.size()) {
            cnt[tree[right]]++;
            while(cnt.size() > 2) {
                cnt[tree[left]]--;
                if(cnt[tree[left]]==0)
                    cnt.erase(tree[left]);
                left++;
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};