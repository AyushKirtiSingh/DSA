class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int max = nums[0];
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(max<=nums[i]){
                max = nums[i];
                ans = i;
            }

        }
        return ans;
        
    }
};