class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result;
        
        for(int i=0;i<nums.size();i++){
            int ans = 0;
            ans = nums[nums[i]];
            result.push_back(ans);
            
        }
        return result;
        
    }
};