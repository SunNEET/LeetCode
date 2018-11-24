class Solution {
    /*
        h-index 的意思是有 h 個 paper 引用次數大於等於 h
        e.g. [0,1,3,5,6] => 3,5,6 3個 paper 都 >= 3, h=3
        e.g. [100] => 100 1個 paper >= 1, h=1
        e.g. [0,1,5,5,6,7] => 5,5,6,7 4個 paper >= 4, h=4
        
        基本思路：排序，然後讓每個 citation c[i] 去跟 length - i 做比較。
        length - i 可以理解為有"多少paper"的引用數比 c[i] 還多or相等(因為排序過了)  
        所以只要判斷 c[i] 有沒有 >= length-i(h) 就好了(因為後面也會滿足)
        概念有點像枚舉 h，從最大可能的 h (len-i,i=0) 開始枚舉

        clarify: 
        (1) Will the input be empty?
        (2) Does it contain negative numbers?
        (3) Does it contain duplicates?
    */
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        int len = citations.size();
        sort(citations.begin(), citations.end());
        for(int i=0; i<len; i++) {
            if(citations[i] >= len - i)
                return len - i;
        }
        return 0;
    }
};

class Solution {
    /*
        更快的作法，把論文引用的次數用 hashmap 紀錄。
        map 只紀錄 0 ~ citations 的 size，因為我們的做法其實就是類似枚舉 h-index。
        而 h-index 最大就是 paper 的總數而已，引用次數超過 input 長度的都歸類在 hash[len]。
        這是因為接下來要做類似 counting sort 的事，用for loop 從 hashmap 後面往回 iterate
        過程中的 cnt 總和就表示現在有多少 paper，而這 cnt 張 paper 的 citation 都會大於 i
        
        Time: O(N), Space: O(N)
    */
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> hash(len+1, 0);
        for(int i=0; i<len; i++){
            if(citations[i] > len)
                hash[len]++;
            else
                hash[citations[i]]++;
        } 
        int t = 0;
        
        // 枚舉 h-index
        for(int i=len; i>=0; i--) {
            t += hash[i]; // t 代表目前有多少張 paper，且這些 paper 的 citation 次數都會 >= i
            if(t >= i)
                return i;
        }
        return 0;
    }
};