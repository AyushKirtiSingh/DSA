class Solution {
public:
    bool searchinrow(vector<vector<int>>& matrix, int target, int row){  //O(logn)
        int n = matrix[0].size();
        int st = 0, end = n-1;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(target == matrix[row][mid]){
                return true;
            }
            else if(target>matrix[row][mid]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;

    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, endr = m - 1;

        while(sr<=endr){   //O(logm)     TOTAL TC = O(log(m*n))
            int midrow = sr + (endr - sr)/2;
            if(target>=matrix[midrow][0] && target<=matrix[midrow][n-1]){
                //found the row=> BS on this row
                return searchinrow(matrix,target,midrow);
            }
            else if(target>=matrix[midrow][n-1]){
                //down = right
                sr = midrow + 1;
            }
            else {
                //up = left
                endr = midrow - 1;
            }
        }
        return false;
        
    }
};