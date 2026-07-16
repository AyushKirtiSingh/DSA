class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        long long sum = 0;
        int maxval = 0;
        for(int i=0;i<nums.size();i++){
            maxval = max(maxval,nums[i]);
            long long gcd1 = std::gcd(maxval,nums[i]);
            result[i] = gcd1;
        }

        sort(result.begin(),result.end());
        long long l = 0;
        long long r = result.size()-1;

        while(l<r){
            long long gcd2 = std::gcd(result[l],result[r]);
            sum += gcd2;
            l++;
            r--;
        }
        return sum;
        
    }
};