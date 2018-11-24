class Solution {
    /*
        簡化問題，結合三條敘述(實際上第三條用不到)，A 只會對 B 的年紀落在 (0.5*A + 7, A] 發出好友請求
        為了快速查詢有多少人滿足 (0.5*A + 7, A]，這邊要同時用到 hashMap 和 prefixSum，
        先用 map 算出不同年齡的數量，然後再掃一遍 map 得到 prefixSum
        
        clarify:
        (1) Is this input list sorted?
        (2) Does the list contain zero or negative number?
        (3) Will people make friend request to themselves?
        (4) How old is the oldest age that will appear in the input?
        
    */
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> cnt(121,0);
        vector<int> prefixSum(121,0);
        for(int i=0; i<ages.size(); i++) cnt[ages[i]]++;
        for(int i=1; i<=120; i++) prefixSum[i] = prefixSum[i-1] + cnt[i];
        // Since 0.5*A + 7 always >= A when A < 15, we need to start from 15, or the nums might be 0 or negatives
        int res = 0;
        for(int A=15; A<=120; A++) {
            if(cnt[A] == 0) continue;
            int nums = prefixSum[A] - prefixSum[A/2+7];
            res += cnt[A]*(nums-1); // 要把自己扣掉
        }
        return res;
    }
};