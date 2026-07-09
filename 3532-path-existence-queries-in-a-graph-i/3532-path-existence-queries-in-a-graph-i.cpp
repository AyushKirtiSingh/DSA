class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        if(n==0)return {};

        vector<int> group(n,0);
        int currentgroup = 0;
        

        for(int i=1;i<n;i++){
            
            if(nums[i] - nums[i-1] > maxDiff){
                currentgroup++;
            }
            group[i] = currentgroup;
            
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for(const auto &q : queries){
            int x = q[0];
            int y = q[1];
            ans.push_back(group[x]==group[y]);
            
        }

        return ans;
        
    }
};