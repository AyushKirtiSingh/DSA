class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n==2){
            return true;
        }
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        int x0 = x2 - x1;
        int y0 = y2 - y1;

        for(int i=2;i<n;i++){
            int x = coordinates[i][0] - coordinates[0][0]; 
            int y = coordinates[i][1] - coordinates[0][1];

            if(y0 * x != y * x0){
                return false;
                
            }
        }
        return true;
        
    }
};