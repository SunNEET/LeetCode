class Solution {
    /*
        2 pointer + 一個用來填答案的pointer
    */
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int left = 0, right = A.size()-1;
        for(int ans_idx = A.size()-1; ans_idx>=0; ans_idx--) {
            if(abs(A[left]) > abs(A[right])) {
                res[ans_idx] = A[left]*A[left];
                left++;
            } else {
                res[ans_idx] = A[right]*A[right];
                right--;
            }
        }
        return res;
    }
};