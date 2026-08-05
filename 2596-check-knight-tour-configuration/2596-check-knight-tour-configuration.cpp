class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int r, int c, int n, int expval){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expval){
            return false;    //it checks the boundary condition as well as the element at position of grid is equal to expval or not
        }

        if(pow(n,2)-1==expval){   //it checks whether the last cell of the grid where the knight can visit is equal to expval or not
            return true;
        }

        // 8 possible moves
        bool ans1 = isvalid(grid,r-2,c+1,n,expval+1);
        bool ans2 = isvalid(grid,r-1,c+2,n,expval+1);
        bool ans3 = isvalid(grid,r+1,c+2,n,expval+1); //for each cell the we check every possible moves of the knight and check whether any of the move is possible to reach the next value i.e expval + 1.
        bool ans4 = isvalid(grid,r+2,c+1,n,expval+1);
        bool ans5 = isvalid(grid,r+2,c-1,n,expval+1);
        bool ans6 = isvalid(grid,r+1,c-2,n,expval+1);  //backtracking is done when the possible route does not lead to the next expval
        bool ans7 = isvalid(grid,r-1,c-2,n,expval+1);
        bool ans8 = isvalid(grid,r-2,c-1,n,expval+1);

        return (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8);  //if any of the route gives true value then it returns true
    }

    bool checkValidGrid(vector<vector<int>>& grid) {  //Time complexity : O(8^n^2) && Space complexity : O(n^2). due to the call stack
        return isvalid(grid,0,0,grid.size(),0);
        
    }
};