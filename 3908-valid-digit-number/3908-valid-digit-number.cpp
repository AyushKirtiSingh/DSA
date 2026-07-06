class Solution {
public:
    bool validDigit(int n, int x) {
        string str = to_string(n);
        char ans = x + '0';
        
        if(str.length()>1 && str.find(ans)!=string :: npos && str[0]!=ans){
            return true;
        }
        else if(str.length()==1){
            return false;
        }
        else{
            return false;
        }
        
        
    }
};