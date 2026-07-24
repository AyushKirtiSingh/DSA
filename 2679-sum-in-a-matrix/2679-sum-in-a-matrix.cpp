class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(),nums[i].end());
        }

        for(int j=0;j<nums[0].size();j++){
            int maxval = 0;
            for(int i=0;i<nums.size();i++){
                maxval = max(maxval,nums[i][j]);

            }
            sum += maxval;
        }
        return sum;
        
    }
};