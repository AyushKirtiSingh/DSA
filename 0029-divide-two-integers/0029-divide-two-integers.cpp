class Solution {
public:
    int divide(long dividend, long divisor) {
        long quotient = dividend/divisor;
        if(quotient>pow(2,31)-1){
            quotient = pow(2,31)-1;
        }
        if(quotient<pow(-2,31)){
            quotient = pow(-2,31);
        }
        return quotient;
        
    }
};