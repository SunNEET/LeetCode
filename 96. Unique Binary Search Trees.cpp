class Solution {
    // https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
    // 這解釋講得太好了，本題可以直接當成卡特蘭數計算是一個化繁為簡的結果
    // 令G(n)為長度為n的序列所能組合出的unique BST數量
    // F(i,n)為以i為root, 有數字1~n的陣列, 所能組合出的unique BST數量
    // 因此G(n)=F(1,n)+F(2,n)+....+F(n,n)
    // 而F(i,n)的結果實際上又可以拆成兩個G相乘
    // 以F(3,7)為例，[1,2,3,4,5,6,7]的序列以3為root，會被分成左邊的[1,2]和右邊的[4,5,6,7]
    // 而這兩個的BST數量就是G(2)和G(4)，組合起來就是G(2)*G(4)
    // 所以式子可以推倒成G(n)=sigma(G(i-1)*G(n-i)), 把每種以i為底的結果都加起來
    
public:
    int numTrees(int n) {
        vector<int> G(n+1);
        // bottom cases, 沒有數跟只有一個數, 都只有一種BST
        G[0]=G[1]=1;
        // i枚舉n的長度
        for(int i=2;i<=n;i++) {
            // j枚舉當root的節點
            for(int j=1;j<=i;j++) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};