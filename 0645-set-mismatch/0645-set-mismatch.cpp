class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector <int> result;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==nums[i+1]){
                result.push_back(nums[i]);
                break;
                
            }
        }
        for(int i=1;i<=nums.size();i++){
                if(find(nums.begin(),nums.end(),i) == nums.end()){
                    result.push_back(i);

                }
        }
            
        return result;
    
        
        
    }
};