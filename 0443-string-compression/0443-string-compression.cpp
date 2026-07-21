class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        for(int i=0;i<n;i++){       
            char ch = chars[i];
            int count = 0;

            while(i<n && chars[i]==ch){     //used to find count of continuous characters
                count++;
                i++;
            }
            if(count==1){              //if count = 1 only charcter will be replaced in place of original array
                chars[idx++] = ch;
            }
            else{                  //else first replace the character in the place and then its count in char form in the next index
                chars[idx++] = ch;
                string str = to_string(count);
                for(char dig : str){
                    chars[idx++] = dig;
                }
            }
            i--;       //it is used to control the movement of i which is inc by 1 and misses one element due to while loop
        }
        chars.resize(idx);
        return idx;
        
    }
};