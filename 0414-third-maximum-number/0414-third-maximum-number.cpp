class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        vector<int> result;
        for(int x:nums){
            s.insert(x);
        }

        for(int x: s){
            result.push_back(x);
        }

        if(result.size()>=3){
            return result[result.size()-3];
        }
        else{
            return result[result.size()-1];
        }
        
    }
};