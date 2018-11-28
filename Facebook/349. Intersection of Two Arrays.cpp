class Solution {
    /*
        用個set判斷哪些元素在 nums1 有出現過，然後掃nums2遇到重複的就塞進res，然後把那個key刪掉，避免後面又推一樣的元素
        Time complexity: O(n+m)
        Space complexity: O(n)
    */
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s(nums1.begin(), nums1.end());
        for(int i=0; i<nums2.size(); i++)
            if(s.count(nums2[i])>0) {
                res.push_back(nums2[i]);
                s.erase(nums2[i]);    
            }
        return res;
    }
};