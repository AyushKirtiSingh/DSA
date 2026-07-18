class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ans = 0;
        int maxval = INT_MIN;
        int minval = INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxval = max(maxval,nums[i]);
            minval = min(minval,nums[i]);
        }
        ans = std::gcd(minval,maxval);

        return ans;
    }
};