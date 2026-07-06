class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int min = INT_MAX;
            int max = INT_MIN;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0 && nums[i]<min){
                    min = nums[i];
                }
                if(nums[i]>max){
                    max = nums[i];
                }
            }
            if(max!=0){
                    count++;
                    
                }
                else if(max==0){
                    break;
                }
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    nums[i] = nums[i] - min;
                }
                
            }
            
        }
        return count;
    }
};