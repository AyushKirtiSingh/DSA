class Solution {
public:
    int maxDepth(string s) {
        stack<char> s1;
        int maxval = 0;
        int count = 0;

        for(char x : s){
            if(x=='('){
                s1.push(x);
            }
            else if(x==')'){
                count = s1.size();
                maxval = max(count,maxval);
                s1.pop();
            }
            else{
                continue;
            }
        }

        return maxval;
    }
};