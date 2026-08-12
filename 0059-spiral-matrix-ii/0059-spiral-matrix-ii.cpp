class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        // n x n matrix, initially 0
        vector<vector<int>> mat(n, vector<int>(n, 0));

        // Numbers 1 se n² tak fill karenge
        int a = 1;

        // Current layer ki 4 boundaries
        int srow = 0, erow = n - 1;
        int scol = 0, ecol = n - 1;

        while(srow <= erow && scol <= ecol){

            // 1. Top row: left → right
            for(int j = scol; j <= ecol; j++){
                mat[srow][j] = a;
                a++;
            }

            // 2. Right column: top → bottom
            for(int i = srow + 1; i <= erow; i++){
                mat[i][ecol] = a;
                a++;
            }

            // 3. Bottom row: right → left
            for(int j = ecol - 1; j >= scol; j--){

                // Single row ho toh dobara fill nahi karna
                if(srow == erow) break;

                mat[erow][j] = a;
                a++;
            }

            // 4. Left column: bottom → top
            for(int i = erow - 1; i >= srow + 1; i--){

                // Single column ho toh dobara fill nahi karna
                if(scol == ecol) break;

                mat[i][scol] = a;
                a++;
            }

            // Next inner layer par move
            srow++;
            scol++;
            erow--;
            ecol--;
        }

        return mat;
    }
};