class Solution {
public:
    int r;
    long sum=0;
    
    bool isPalindrome(int x) {
        int  temp = x;
        while(x>0){
            r = x%10;
            sum = (sum*10)+r;
            x = x/10;
        }
        if(temp==sum){
            return true;
        }
        else{
            return false;
        }
        
    }
};