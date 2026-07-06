class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int prev = prices[0];

        for(int i=1;i<prices.size();i++){
            if(prices[i]>prev){
                maxprofit += prices[i]-prev;
            }
            prev = prices[i];
        }
        return maxprofit;
        
    }
};