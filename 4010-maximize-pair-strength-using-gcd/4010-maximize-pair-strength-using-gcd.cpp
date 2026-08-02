class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxpair = 0;
        for(long long i=0;i<nums.size();i++){
            
            for(long long j=i+1;j<nums.size();j++){
                long long currpair = 0;
                long long gcd = std::gcd(nums[i],nums[j]);
                currpair = (1LL*nums[i]*nums[j])/pow(gcd,2);  //"The calculation itself is overflowing its current datatype, not necessarily the variable I'm storing the result in.So thats why i am using 1LL"
                maxpair = max(maxpair,currpair);

            }
        }
        return maxpair;
        
    }
};