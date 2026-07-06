class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for(int i=1;i<n;i++){
            int a = i;
            int b = n-i;
            string s = to_string(a);
            string p = to_string(b);
            if(s.find('0')==string::npos && p.find('0')==string::npos){
                result.push_back(stoi(s));
                result.push_back(stoi(p));
                break;
            }
        }
        return result;
        
        
    }
};