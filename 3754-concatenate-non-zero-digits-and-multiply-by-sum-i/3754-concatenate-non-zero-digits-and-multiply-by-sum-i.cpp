class Solution {
public:
    long long sumAndMultiply(int n) {
        string q = "";
        int sum = 0;
        string str = to_string(n);
        for(int i=0;i<str.length();i++){
            if(str[i]!='0'){
                q += str[i];
                char ch = str[i] - '0';
                sum += ch;
            }
        }

        if(n==0){
            return 0;
        }

        long long x = stoll(q);
        return (x * sum);
        
    }
};