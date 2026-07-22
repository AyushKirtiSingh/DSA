class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            int d = 0;
            for(int j=i;j<nums.size();j++){
                d = gcd(d,nums[j]);
                if(d==k){
                    count++;
                }
                
                
            }
        }
        return count;
        
    }
};