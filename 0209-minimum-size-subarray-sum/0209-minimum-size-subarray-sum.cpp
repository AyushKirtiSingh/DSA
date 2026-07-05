class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r;
        int ans = INT_MAX;
        int currentSum = 0;
        
        for(int r=0;r<n;r++){
            currentSum += nums[r];
            while(currentSum>=target){
                ans = min(ans,r-l+1);
                currentSum-=nums[l];
                l++;
            }

        }
        if(ans==INT_MAX){
            return 0;
        }
        else{
            return ans;
        }
        
    }
};