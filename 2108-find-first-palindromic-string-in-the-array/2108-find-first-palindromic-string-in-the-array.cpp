class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        
        for(int i=0;i<words.size();i++){
            string str = words[i];
            bool palindrome = false;
            int left = 0;
            int right = str.length()-1;
            while(left<=right){
                if(str[left]==str[right]){
                    left++;
                    right--;
                    palindrome = true;
                }
                else{
                    palindrome = false;
                    break;
                }
            }
            if(palindrome){
                return str;
            }
        }
        return "";
    }
};