class Solution {
public:
    
    vector <int> result;
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int count = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]>nums[j] && i!=j){
                    count++;
                
                }
                
            }
            result.push_back(count);

            
        }
        return result;
        
    }
};