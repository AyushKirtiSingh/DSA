class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {

        // Lucky numbers ko store karne ke liye answer vector
        vector<int> ans;

        // Har row ko one by one check karenge
        for(int i = 0; i < matrix.size(); i++) {

            // Current row ka minimum element find karna hai
            int minrow = INT_MAX;

            // Us minimum element wale column ka maximum find karenge
            int maxcol = INT_MIN;

            // Minimum element kis column mein hai, uska index store karenge
            int col = 0;


            // Current row ka minimum element find karo
            for(int j = 0; j < matrix[i].size(); j++) {

                if(matrix[i][j] < minrow) {

                    // Ab tak ka smallest element update karo
                    minrow = matrix[i][j];

                    // Minimum element ka column store karo
                    col = j;
                }
            }


            // Ab usi column ko check karenge
            // Column fix rahega, row (k) change hogi
            for(int k = 0; k < matrix.size(); k++) {

                // Puri column ka maximum element find karo
                maxcol = max(matrix[k][col], maxcol);
            }


            // Lucky number ki condition:
            // Element apni row ka minimum
            // AND
            // apni column ka maximum hona chahiye
            if(minrow == maxcol) {

                // Agar dono same hain, toh ye lucky number hai
                ans.push_back(minrow);
            }
        }

        // Saare lucky numbers return karo
        return ans;
    }
};