class Solution {
    // *不會出現invalid input
    // 思路: 數有幾個船隻的左上角, 因為遍歷是從左上到右下
    // 所以一艘有效的船肯定是他的最左或最上會先被掃到, 把這點當作他的起點
    // 因此我們只要數有幾個起點就行了
public:
    int countBattleships(vector<vector<char>>& board) {
        if(!board.size()) return 0;
        int cnt = 0;
        for(int i=0;i<(int)board.size();i++) {
            for(int j=0;j<(int)board[i].size();j++) {
                // 判斷他是不是船隻最左或最右
                if(board[i][j]=='X' && 
                   (i==0 || board[i-1][j]!='X') &&
                   (j==0 || board[i][j-1]!='X'))
                    cnt++;
            }
        }
        return cnt;
    }
};