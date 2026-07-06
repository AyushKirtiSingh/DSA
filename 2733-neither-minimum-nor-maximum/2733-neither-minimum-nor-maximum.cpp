class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=2){
            return -1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[0] && nums[i]<nums[nums.size()-1]){
                return nums[i];
                break;
            }
        }
        return 0;
        
    }
};