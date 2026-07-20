class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int column = grid[0].size();

        int total = row * column;

        k = k % total;

        for(int i=0;i<k;i++){           // part where the shuffling is done on grid k times
            int curr = grid[0][0];
            int prev = grid[0][0];

            for(int r=0;r<row;r++){
                for(int c=0;c<column;c++){
                    prev = curr;
                    curr = grid[r][c];
                    grid[r][c] = prev;
                }
            }

            grid[0][0] = curr;
        }

        vector<vector<int>> ans;

        

        for(int i=0;i<row;i++){

            vector<int> temp;

            for(int j=0;j<column;j++){
                temp.push_back(grid[i][j]);
            }
            ans.push_back(temp);
            
        }

        return ans;

        
    }
};