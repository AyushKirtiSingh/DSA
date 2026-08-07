class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i=num1;i<=num2;i++){
            int peak = 0;
            int valley = 0;
            string str = to_string(i);
            for(int i=1;i<str.length()-1;i++){
                char ch1 = str[i]-'0';
                char ch2 = str[i-1]-'0';
                char ch3 = str[i+1]-'0';
                if(ch1>ch2 && ch1>ch3){
                    peak++;
                }
                if(ch1<ch2 && ch1<ch3){
                    valley++;
                }
                
            }
            count += peak;
            count += valley;
        }

        return count;
        
        
    }
};