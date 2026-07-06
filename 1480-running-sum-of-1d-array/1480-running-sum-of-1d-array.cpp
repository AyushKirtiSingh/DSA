class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int count = 0;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            count += nums[i];
            result.push_back(count);

        }
        return result;
        
    }
};