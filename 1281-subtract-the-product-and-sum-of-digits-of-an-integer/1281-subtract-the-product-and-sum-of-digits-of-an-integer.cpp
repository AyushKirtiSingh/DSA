class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        string ans = to_string(n);
        
        for(int i=0;i<ans.length();i++){
            int digit = ans[i] - '0';
            
            product *= digit;
            
            sum += digit;
        }
        int subtract = product - sum;
        return subtract;
        
    }
};