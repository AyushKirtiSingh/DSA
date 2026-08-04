class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxval = INT_MIN;
        int minval = INT_MAX;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            maxval = max(nums[i],maxval);
            minval = min(nums[i],minval);
        }

        for(int i=minval;i<=maxval;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                ans.push_back(i);

            }
        }
        return ans;
        
    }
};