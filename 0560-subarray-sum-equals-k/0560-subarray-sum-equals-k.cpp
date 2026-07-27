class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int>prefixsum(n,0);
        prefixsum[0] = nums[0];
        unordered_map<int,int>m;

        for(int i=1;i<n;i++){
            prefixsum[i] = prefixsum[i-1]+nums[i];
        }

        for(int j=0;j<n;j++){             //T.C = O(N) && S.C : O(N)
            if(prefixsum[j]==k){
                count++;
            }
            
            int val = prefixsum[j] - k;
            if(m.find(val)!=m.end()){
                count += m[val];
            }
                
            if(m.find(prefixsum[j])==m.end()){
                 m[prefixsum[j]]=0;
            }
               
            
            m[prefixsum[j]]++;
        }
        return count;
    }
};