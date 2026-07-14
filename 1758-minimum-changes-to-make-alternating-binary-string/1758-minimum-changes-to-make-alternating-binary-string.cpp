class Solution {
public:
    int minOperations(string s) {
        int startswith0 = 0;
        int startswith1 = 0;


        for(int i=0;i<s.length();i++){
            if(i%2==0){      //even index               //01010101010.... pattern 
               if(s[i]!='0'){
                startswith0++;
               }
            }
            else{            //odd index
                if(s[i]!='1'){
                    startswith0++;
                }
            }

            if(i%2==0){    //even index                 //1010101010.... pattern 
               if(s[i]!='1'){
                startswith1++;
               }
            }
            else{         //odd index
                if(s[i]!='0'){
                    startswith1++;
                }
            }
        }

        return min(startswith0,startswith1);
        
    }
};