class Solution {
public:
    bool isSelfdivide(int n){
            string str = to_string(n);
            
            for(int i=0;i<str.length();i++){
                char ch = str[i] - '0';
                if(ch==0 || n%ch!=0){
                    return false;
                }
                
            }
            return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector <int> result;
        for(int i=left;i<=right;i++){
            if(isSelfdivide(i)==true){
                result.push_back(i);
            }
        }
        return result;
    }
};