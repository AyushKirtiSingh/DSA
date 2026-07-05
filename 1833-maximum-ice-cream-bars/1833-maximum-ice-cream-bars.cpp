class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        int ans = 0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins && count<coins){
                count += costs[i];
                if(count>coins){
                    break;
                }
                ans++;
                

            }
            

            
        }
        return ans;
        
    }
};