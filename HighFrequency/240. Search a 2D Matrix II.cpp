class Solution {
    // 從最右上角開始搜，如果最右上角的元素 a[i][j] < target，那比他大的就會在下面或左下方，但總之先往下移動，i++
    // 畢竟就算在左下，因為橫的也是有排序的，所以往下移動後出現 a[i][j] > target 的場合，再往左移動就好。
    // 
    // 同理如果 a[i][j] > target，那比它小的就肯定只會在左邊了(這排下面都比他大)，j--
    // 所以可以從右上角開始一步一步減少選項
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int i=0, j=matrix[0].size()-1;
        while(i < matrix.size() && j >= 0) {
            if(matrix[i][j] < target) {
                i++;
            } else if(matrix[i][j] > target) {
                j--;
            } else {
                return true;
            }
        }
        return false;
    }
};