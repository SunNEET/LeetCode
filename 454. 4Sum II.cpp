class Solution {
    // O(N^2)作法, 拆成AB跟CD兩組, 把AB所有的總和都先算出來存到map
    // 然後再去該map裡找有沒有這個能跟(C+D)加起來變成0的值, 也就是-(C+D)
    // 有的話表示這組ABCD加起來會等於0
    // 把它出現的次數累加到cnt
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = (int)A.size();
        if(!len) return 0;
        unordered_map<int,int> ab; // <sum,count>
        for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++) {
                ab[A[i]+B[j]]++; 
            }
        }
        int cnt = 0;
        for(int k=0;k<len;k++){
            for(int l=0;l<len;l++) {
                auto it = ab.find(0-C[k]-D[l]);
                if(it!=ab.end())
                    cnt+=it->second;
            }
        }
        return cnt;
    }
};