class Solution {
public:
    vector <int> result;
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index;
        for(int i=0;i<nums.size();i++){
            index = abs(nums[i]) - 1;
            if(nums[index]<0){
                continue;
            }
            else{
                nums[index]*= -1;
            }
           
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                result.push_back(i+1);
            }
        }
        return result;
       
        
        
        
    }
};