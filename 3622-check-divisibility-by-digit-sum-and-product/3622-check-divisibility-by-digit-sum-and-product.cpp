class Solution {
public:
    bool checkDivisibility(int num) {
        int temp = num;
        int sum = 0;
        int prod = 1;
        while(temp!=0){
            int digit = temp%10;
            temp = temp/10;
            sum += digit;
            prod *= digit;
        }

        if(num % (sum + prod)==0){
            return true;
        }
        else{
            return false;
        }
    }
};