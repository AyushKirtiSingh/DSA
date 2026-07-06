class Solution {
public:
    string interpret(string command) {
        string ans;
        for(int i=0;i<command.size();i++){
            //string str = to_string(command[i]);
            if(command[i]=='G'){
                ans+="G";
            }
            else if(command.substr(i,2)=="()"){
                ans+="o";
            }
            else if(command.substr(i,4)=="(al)"){
                ans+="al";
            }
        }
        return ans;
        
    }
};