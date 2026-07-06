class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        
        int n2 = n+k;
        int sum = 0;
        for(int i=1;i<=n2;i++){
            if(abs(n-i)<=k && (n&i)==0){
                sum += i;

            }
        }
        return sum;
    }
};