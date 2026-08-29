class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int> m;
        vector<int> ans;

        // Count the total occurrences of each element.
        for(int v : nums){
            if(m.find(v)==m.end()){
                m[v] = 1;
            }
            else{
                m[v]++;
            }
        }

        // Store the index of each occurrence of x.
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

        // Answer each query using the stored occurrence indices.
        for(int i=0;i<queries.size();i++){

            // If the requested occurrence does not exist.
            if(queries[i]>m[x]){
                ans.push_back(-1);
            }
            else{
                // Return the index of the requested occurrence.
                ans.push_back(q[queries[i]]);
            }
        }

        return ans;
    }
};

