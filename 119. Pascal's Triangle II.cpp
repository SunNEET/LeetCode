class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        // 直接開好那行的大小，然後初始化成1
        ans.resize(rowIndex+1, 1);
        for(int i=0;i<rowIndex+1;i++) {
            // 頭尾(0,i)不管，只處理中間，並且由後往前做
            // 這個作法tricky的點在於 1.後面還沒用到的部分全都是1 2.後面的值覆蓋後不會影響前面的結果
            // 先把三角形看成先前A[i][j] = A[i-1][j-1] + A[i-1][j] 的形式 (實際上的操作是a[j] = a[j-1] + a[j])
            // 比方說A[4][2] = A[3][1] + A[3][2]，在只有1d array的情況下A[4][2]會直接覆蓋到A[3][2]的值
            // 而這樣做就會讓A[4][3](=A[3][2]+A[3][3])的計算出錯，因為A[3][2]的值變了
            // 但如果反過來做，先做A[4][3]然後覆蓋到A[3][3]，不會影響A[4][2]的計算
            // 而我也不需要在覆蓋玩以後幫array補1(因為後面全都是1)
            for(int j=i-1;j>=1;j--) {
                ans[j] = ans[j-1] + ans[j];
            }
        }
        return ans;
    }
};