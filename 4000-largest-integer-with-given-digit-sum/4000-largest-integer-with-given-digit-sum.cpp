class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n){       //largest possible consists only 9 and for n size the sum is 9*n and it should be less than s to be valid
            return -1;
        }

        string str = "";

        for(int i=0;i<n;i++){
            int digit = min(9,s);     // placing the largets possible first digit
            char ch = digit + '0';    //converting to string na dcharacter to concatenate numbers
            str += ch;
            s -= digit;     //decreasing s by digit to cal culate next possible largest digit
            
        }

        return stoi(str);
    }
};