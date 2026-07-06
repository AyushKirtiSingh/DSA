class Solution {
public:
    
    bool isPathCrossing(string path) {
        unordered_set<string> st;
        int x=0;
        int y=0;
    
        string key = to_string(x) + " " + to_string(y);
        st.insert(key);
        for(int i=0;i<path.length();i++){
            if(path[i]=='N'){
                y++;

            }
            else if(path[i]=='S'){
                y--;

            }
            else if(path[i]=='E'){
                x++;

            }
            else if(path[i]=='W'){
                x--;

            }
            string key = to_string(x) + " " + to_string(y);
            if(st.find(key)!=st.end()){
                return true;
            }
            st.insert(key);
        }
        
        return false;
        
    }
};