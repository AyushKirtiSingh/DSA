class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long MOD = 1000000007;
        
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            long long width = 0;
            long long d = 0;
            string ans1 = "";
            string ans2 = "";
            width = nums[i] % 10;
            d = floor(nums[i]/10);
            string str = to_string(d);
            for(int i=0;i<width;i++){
                ans1 += str[i];
            }
            long long x = 0;
            x = stoll(ans1);
            for(int i=width;i<str.length();i++){
                ans2 += str[i];
            }
            long long y = 0;
            y = stoll(ans2);

            long long prod = 1;
            int k=0;
            long long temp = y;
            while(y>0){
                if(y%2!=0){
                    prod *= x;
                }
               
                prod = prod % MOD;
                k++;
                y = y/2;
                x = (x * x) % MOD;
            }
            
            sum += prod;
        }

        return (sum % MOD);
    }
};