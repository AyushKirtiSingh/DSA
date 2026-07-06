class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector <int> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){
            int num1 = nums[i];
            int num2 = nums[i+1];
            result.push_back(nums[i+1]);
            result.push_back(nums[i]);
        }
        return result;
        
    }
};