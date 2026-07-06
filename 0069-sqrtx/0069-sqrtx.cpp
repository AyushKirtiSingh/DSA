class Solution {
public:
    int mySqrt(int x) {
        for(int i=0;i<=pow(2,35);i++){
            if(i==x){
                return sqrt(x);
            }
        }
        return 0;
        
    }
};