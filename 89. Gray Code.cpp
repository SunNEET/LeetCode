class Solution {
    /*
        bit operation 解法，從 000.....000 開始，
        把目前res裡有個第i個bit設成1，然後push進res裡，以此類推
        要注意從 res 裡拿結果出來改的順序必須是反著來的，
        這樣才剛好可以讓他們之間的 bit 只差1
    */
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for(int i=0; i<n; i++) {
            int sz = res.size();
            for(int j=sz-1; j>=0; j--)
                res.push_back(res[j]|1<<i);
        }
        return res;
    }
};

class Solution {
    /*
        DFS + bitset + flip
        想法類似，只是用backtracking還需要extra space
    */
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        DFS(bits, result, n);
        return result;
    }
private:
    void DFS(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        } else {
            DFS(bits, result, k-1);
            bits.flip(k-1);
            DFS(bits, result, k-1);
        }
    }
};