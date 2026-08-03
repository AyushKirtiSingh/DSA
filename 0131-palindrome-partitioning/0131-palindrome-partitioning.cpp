class Solution {
public:
    bool ispalindrome(string s){        //function used for checking a string palindrome or not
        string str1, str2;
        for(int i=0;i<s.length();i++){
            str1 += s[i];
        }

        for(int i=s.length()-1;i>=0;i--){
            str2 += s[i];
        }

        if(str1==str2){
            return true;
        }
        else{
            return false;
        }
    }

    void getallparts(string s,vector<string> &partitions,vector<vector<string>> &ans){
        if(s.size()==0){            //BASE CASE
            ans.push_back(partitions);
            return;            //storing answer
        }

        for(int i=0;i<s.length();i++){      //using for loop for applying cuts at various index
            string part = s.substr(0,i+1);   //string got after first cut
            if(ispalindrome(part)){
                partitions.push_back(part);
                getallparts(s.substr(i+1),partitions,ans); //function called for remaining string
                
                partitions.pop_back();   //backtracking. poping to get new substring which is palindrome by removing the old substring
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;    // calling of the palindromic partitioning function

        getallparts(s,partitions,ans);

        return ans;
        
    }
};