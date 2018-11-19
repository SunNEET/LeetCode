class Solution {
    /*
        直接用矩陣乘法做，暫時不考慮稀疏矩陣的特性
        C[i][j] += A[i][k]*B[k][j]
    */
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int r = A.size(), c = A[0].size(), cB = B[0].size();
        vector<vector<int>> C(r,vector<int>(cB,0));
        for(int i=0;i<r;i++) {
            for(int k=0;k<c;k++) {
                if(A[i][k]!=0) {
                    for(int j=0;j<cB;j++) {
                        if(B[k][j]!=0) {
                            C[i][j] += A[i][k]*B[k][j];
                        }
                    }
                }
            }
        }
        return C;
    }
};