class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        string str = to_string(num);
        for(int i=0;i<str.length();i++){
            char ch = str[i] - '0';
            if(num%ch==0){
                count++;
            }
        }
        return count;
        
    }
};