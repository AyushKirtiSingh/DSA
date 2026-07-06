class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=10){
                count1+=nums[i];
            }
            else{
                count2+=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<10){
                count3+=nums[i];
            }
            else{
                count4+=nums[i];
            }
        }
        if(count1>count2 || count3>count4){
            return true;
        }
        else{
            return false;
        }
       
        
       
        
        
    }
};