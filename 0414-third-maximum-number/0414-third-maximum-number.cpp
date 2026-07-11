class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int maxVal = INT_MIN;
        int count = 1;
        int ans = 0;
        if(nums.size()==2){
            ans = max(nums[0],nums[1]);
            return ans;
        }
        if(nums.size()==1){
            return nums[0];
        }

        if(nums.size()==3){
            if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2]){
                return max(nums[0],max(nums[1],nums[2]));
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                count++;
                ans = nums[i-1];
            }
            if(count==3){
                return ans;
            }
        }
        if(count<3){
            for(int i=0;i<nums.size();i++){
                maxVal = max(maxVal,nums[i]);
            }
            return maxVal;
        }
        return ans;
    }
};