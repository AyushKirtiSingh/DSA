class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& nums) {
        int piv = -1;
        int n = nums.size();

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                piv = i;
                break;
            }
        }

        if(piv==-1){
            return nums;
        }

        for(int i=n-1;i>=0;i--){
            if(nums[i]<nums[piv] && nums[i]!=nums[i-1]){
                swap(nums[i],nums[piv]);
                break;
            }
        }

        return nums;
        
    }
};