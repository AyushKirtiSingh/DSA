class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = -1;

        for(int x : nums){
            m[x]++;
        }

        int maxval = 0;
        for(auto it : m){
            if(it.first%2==0 && it.second==maxval){
                ans = min(ans,it.first);
                maxval = it.second;
            }
            else if(it.first%2==0 && it.second>maxval){
                ans = it.first;
                maxval = it.second;
            }
            
        }

        return ans;
    }
};