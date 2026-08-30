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

            // Last digit se width nikal rahe hain
            width = nums[i] % 10;

            // Last digit hata kar actual encoded number nikal rahe hain
            d = floor(nums[i]/10);

            string str = to_string(d);

            // Width ke according x ke digits le rahe hain
            for(int i=0;i<width;i++){
                ans1 += str[i];
            }

            long long x = 0;

            // x ko string se integer mein convert kar rahe hain
            x = stoll(ans1);

            // Remaining digits se y bana rahe hain
            for(int i=width;i<str.length();i++){
                ans2 += str[i];
            }

            long long y = 0;

            // y ko string se integer mein convert kar rahe hain
            y = stoll(ans2);

            long long prod = 1;
            int k=0;
           

            // Binary exponentiation se x^y calculate kar rahe hain
            while(y>0){

                // Agar exponent odd hai, current x answer mein multiply hoga
                if(y%2!=0){
                    prod *= x;
                }
               
                // Overflow avoid karne ke liye modulo le rahe hain
                prod = prod % MOD;

                k++;

                // Exponent ko half kar rahe hain
                y = y/2;

                // Base ko square karke modulo le rahe hain
                x = (x * x) % MOD;
            }
            
            // Current decoded power ko total sum mein add kar rahe hain
            sum += prod;
        }

        // Final answer ko modulo ke saath return kar rahe hain
        return (sum % MOD);
    }
};