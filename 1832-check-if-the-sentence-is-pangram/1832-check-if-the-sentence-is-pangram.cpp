class Solution {
public:
    bool checkIfPangram(string sentence) {
        int count = 1;
        sort(sentence.begin(),sentence.end());
        for(int i=0;i<sentence.length()-1;i++){
            if(sentence[i]!=sentence[i+1]){
                count++;
            }

        }
        if(count==26){
            return true;
        }
        else{
            return false;
        }
        
        
    }
};