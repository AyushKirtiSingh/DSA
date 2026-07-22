class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int d = 0;
            for(int j=i;j<nums.size();j++){
                d = gcd(d,nums[j]);       //calculate one subarray gcd and using previous subarray gcd to calculate next subarray gcd
                if(d==k){
                    count++;
                }
                
                
            }
        }
        return count;
        
    }
};