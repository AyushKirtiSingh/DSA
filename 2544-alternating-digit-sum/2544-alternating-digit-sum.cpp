class Solution {
public:
    int alternateDigitSum(int n) {
        string str = to_string(n);
        int sum = 0;
        for(int i=0;i<str.length();i++){
            char ch = str[i] - '0';
            if(i%2==0){
                ch *= 1;
            }
            if(i%2!=0){
                ch *= -1;
            }
            sum += ch;
        } 
        return sum;
        
    }
};