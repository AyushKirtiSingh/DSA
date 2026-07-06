class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(nums[i]==nums[j] && i!=j){
                    ans ^= nums[i];
                }

            }
        }
        return ans;
    }
};