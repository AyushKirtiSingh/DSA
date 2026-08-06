class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            string str = to_string(i);
            int product = 1;
            for(int i=0;i<str.length();i++){
                char ch = str[i] - '0';
                product *= ch;
            }
            if(product%t==0){
                return i;
            }
        }
        return 0;
        
    }
};