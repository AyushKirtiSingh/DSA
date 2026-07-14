//Index : 0 1 2 3 4 5
/*Pattern 1
        0 1 0 1 0 1
                                    //this is the basic idea of this problem
Pattern 2
        1 0 1 0 1 0

Now memorize only these four rules:

Pattern 1
Even index → '0'
Odd index → '1'
Pattern 2
Even index → '1'
Odd index → '0'*/

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