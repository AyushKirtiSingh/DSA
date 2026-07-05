class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        long long sum = 0;

        while(left<=right){
            sum = left*left + right*right;
            if(sum<c){
                left++;
            }
            else if(sum>c){
                right--;
            }
            else if(sum==c){
                return true;
            }
            
        }
        return false;
        
        
    }
};