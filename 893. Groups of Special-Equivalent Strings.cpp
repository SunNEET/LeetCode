class Solution {
    /*
        題目很難懂，意思是說奇數元素互換和偶數元素互換後會長一樣的可以分成一組，問 A 裡的字串會分成幾組。
        Naive way
        Solution: 用 set 存字串，分別 count 每個 word 奇偶字母的出現次數，sort後丟到set
        Time Complexity: Say n = A.size(), w = word.length => O(n*wlogw)
    */
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> group;
        for(int i=0;i<(int)A.size();i++) {
            string word = A[i];
            string odd = "";
            string even = "";
            for(int j=0;j<(int)word.size();j++) {
                if(j%2==0) 
                    even += word[j];
                else 
                    odd += word[j];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            group.insert(even+odd);
        }
        return (int)group.size();
    }
};