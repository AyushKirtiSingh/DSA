class Solution {
public:
    bool isPerfectSquare(int num) {
        bool ans = false;
        for(long i=1;i<=num;i++){
            
            if(i*i==num){
                ans = true;
                break;
            }
            
            
        }
        return ans;
        
    }
};