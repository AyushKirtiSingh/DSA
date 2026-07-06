class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int count1 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count++;
                count1 = max(count1,count);
            }
            else{
                count = 0;
            }
            
        }
        return count1;
        
        
    }
};