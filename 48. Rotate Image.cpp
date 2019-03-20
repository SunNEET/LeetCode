class Solution {
    /*
        關鍵，斜對稱交換(swap the symmetry)
        swap(M[i][j], M[j][i])
        [1,2,3]    [1,4,7]
        [4,5,6] => [2,5,8]
        [7,8,9]    [3,6,9]
        
        but we want it to be rotated clockwise, 
        so we have to reverse the original array at the beginning.
        [7,8,9]    [7,4,1]  
        [4,5,6] => [8,5,2]
        [1,2,3]    [9,6,3]
    */
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++) {
            for(int j=i+1; j<matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};