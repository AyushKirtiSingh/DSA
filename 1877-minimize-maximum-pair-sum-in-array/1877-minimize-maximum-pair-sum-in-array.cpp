class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxpairsum = 0;
        sort(nums.begin(),nums.end());

        int i=0, j=nums.size()-1;

        while(i<j){
            int sum = nums[i] + nums[j];
            maxpairsum = max(maxpairsum,sum);
            i++, j--;
        }

        return maxpairsum;
        
        
    }
};