class Solution {
    /*
        兩次二分搜解決
        或是也可以直接套用 LC 240 的做法，從右上角開始縮減狀態空間
    */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        // find the row where the solution is
        int l=0, r=matrix.size()-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(matrix[mid][0] > target) {
                r = mid-1;
            } else if(matrix[mid][0] < target) {
                l = mid+1;
            } else {
                return true;
            }
        }
        // It would be in row[l-1], if l is zero, then there is no such element 
        if(!l) return false;
        int row = l-1;
        int l2 = 0, r2 = matrix[0].size()-1;
        while(l2<=r2) {
            int mid = l2 + (r2-l2)/2;
            if(matrix[row][mid] > target) {
                r2 = mid-1;
            } else if(matrix[row][mid] < target) {
                l2 = mid+1;
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
    /*
        只用一次 binarySearch 的做法，
    */
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();
        int l = 0, r = n*m-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(matrix[mid/m][mid%m] < target)
                l = mid+1;
            else if(matrix[mid/m][mid%m] > target)
                r = mid-1;
            else
                return true;
        }
        return false;
    }
};

