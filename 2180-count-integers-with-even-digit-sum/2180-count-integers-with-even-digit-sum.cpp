class Solution {
public:
    int countEven(int num) {
        int count = 0;
        
        for(int i=1;i<=num;i++){
            string str = to_string(i);
           
                
                if(str.length()==1){
                    char ch = str[0] - '0';
                    if(ch%2==0){
                        count++;
                    }
                    
                }
                else if(str.length()>1){
                    int ans = 0;
                    for(int i=0;i<str.length();i++){
                        char ch = str[i]-'0';
                        ans += ch;
                    }
                    if(ans%2==0){
                        count++;
                    }
                }
                
            
        }
        return count;
        
    }
};