class Solution {
public:
    int myAtoi(string s) {
        // Current index
        int i=0;

        // Default sign positive
        int sign = 1;

        // Sign already use hua hai ya nahi track karne ke liye
        string str = "";

        // Result ko long long mein store karenge
        long long result = 0;

        // int ki minimum aur maximum limit
        long long minval = INT_MIN;
        long long maxval = INT_MAX;

        // Starting ke spaces skip karo
        while(s.length()>i && s[i]==' '){
            i++;
        }

        // Leading spaces hata diye
        s = s.substr(i);

        // String ko left se right traverse kar rahe hain
        for(int i=0;i<s.length();i++){

            // Starting mein '-' mila toh sign negative
            if(s[i]=='-' && str == ""){
                sign *= -1;
                str += s[i];
                continue;
            }

            // Starting mein '+' mila toh sign positive
            else if(s[i]=='+' && str == ""){
                sign = 1;
                str += s[i];
                continue;
            }

            // Character ko digit mein convert kar rahe hain
            int ch = s[i] - '0';

            // Check kar rahe hain ki character digit hai ya nahi
            if(ch>=0 && ch<=9){
                
                // Result update karne se pehle long long overflow check
                if(result > (LLONG_MAX - ch)/10){

                    // Positive number ke liye INT_MAX
                    if(sign==1){
                        return INT_MAX;
                    }

                    // Negative number ke liye INT_MIN
                    else{
                        return INT_MIN;
                    }
                }

                // Current digit ko result mein add karo
                result = result * 10 + ch;

                // Processed character ko store karo
                str+= s[i];
            }

            // Digit nahi mila toh parsing stop
            else{
                break;
            }
        }

        // End mein sign apply kar rahe hain
        result *= sign;
        
        // INT_MAX se bada hai toh INT_MAX return
        if(result >INT_MAX){
            return INT_MAX;
        }

        // INT_MIN se chhota hai toh INT_MIN return
        if(result<INT_MIN){
            return INT_MIN;
        }

        // Agar int range ke andar hai
        else{
            return result;
        }
    }
};