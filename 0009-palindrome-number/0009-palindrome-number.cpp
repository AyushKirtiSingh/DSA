class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp = x;
        int revnum = 0;
        while(temp!=0){
            int digit = temp % 10;
            if(revnum<INT_MIN/10 || revnum>INT_MAX/10){
                return 0;
            }
            revnum = (revnum * 10) + digit;

            temp = temp/10;
            
        }
        if(revnum==x){
            return true;
        }
        else{
            return false;
        }
        
    }
};