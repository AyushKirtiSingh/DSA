class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int v : nums){
            if(m.find(v)==m.end()){
                m[v] = 1;
            }
            else{
                m[v]++;
            }
        }
        unordered_map<int,int> q;
            int count = 0;
            int j = 0;
            while(j<nums.size()){
                if(nums[j]==x){
                    count++;
                    q[count] = j;
                }
                j++;
            }
            
        for(int i=0;i<queries.size();i++){

            if(queries[i]>m[x]){
                ans.push_back(-1);
            }
            else{
                if(q.find(queries[i])==q.end()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(q[queries[i]]);
                }
            }
            
        }
        return ans;


    }
};