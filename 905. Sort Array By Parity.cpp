class Solution {
    /*
        用一個pointer指向現在偶數該填的位置，遇到偶數就把他swap到這個位置，跟 283. Move Zeroes 幾乎一樣。
    */
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int idx_even = 0;
        for(int i=0; i<A.size(); i++) {
            if(!(A[i]&1)) {
                swap(A[idx_even++], A[i]);
            } 
        }
        return A;
    }
};