class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        
        string str2;
        long result;
         for(int i=str.length()-1;i>=0;i--){
            str2 += str[i];
        }
        result = stol(str2);
        if(x<0){
            result *= -1;
        }
        if(result>pow(2,31)-1 || result<pow(-2,31)){
            return 0;
        }
        return result;
        
    }
};