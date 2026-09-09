class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actualsum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            actualsum += nums[i];
        }

        int rangesum = n*(n+1)/2;

        return rangesum - actualsum;
    }
};