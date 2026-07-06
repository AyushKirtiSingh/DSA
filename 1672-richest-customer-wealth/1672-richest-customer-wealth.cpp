class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        vector<int> result;
        for(int i=0;i<accounts.size();i++){
            int wealth = 0;
            for(int j=0;j<accounts[i].size();j++){
                wealth += accounts[i][j];

            }
            result.push_back(wealth);
            
        }
        int max =result[0];
        for(int i=0;i<result.size();i++){
            if(result[i]>max){
                max=result[i];
            }
        }
        return max;
        
    }
};