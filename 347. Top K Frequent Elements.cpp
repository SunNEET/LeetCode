class Solution {
    // 非最佳解, 最佳解有個用bucket sort做O(n)的
    // 直覺做法是直接用map算完frequence然後sort, 就這樣而已
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int num : nums){
            hash[num]++;
        }
        vector<pair<int,int>> fq(hash.begin(), hash.end());
        std::sort(fq.begin(), fq.end(), [](const auto &a, const auto &b) {return a.second > b.second;});
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(fq[i].first);
        return ans;
    }
};