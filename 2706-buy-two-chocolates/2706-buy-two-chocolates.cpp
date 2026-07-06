class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        
        int ans;
        for(int i=0;i<prices.size() - 1;i++){
            
            if(prices[i]+prices[i+1]<= money){
                
                ans = money - (prices[i]+prices[i+1]) ;
                break;
            }
            else{
                return money;
            }
            
            
        }
        return ans;
        
    }
};