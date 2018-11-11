class Solution {
    /*
        solution: 用 status 表示現在的狀態是不確定還是遞增遞減，然後掃過去判斷
        time complexity: O(N)
    */
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size()==1) return true;
        int status = 0; // 0: not sure, 1: increasing, 2: decreasing
        for(int i=1;i<(int)A.size();i++) {
            if(!status) {
                if(A[i]>A[i-1]) status = 1;
                if(A[i]<A[i-1]) status = 2;
            } else { // start increasing or decreasing
                if(status==1 && A[i]<A[i-1]) return false;
                if(status==2 && A[i]>A[i-1]) return false;
            }
        }
        return true;
    }
};