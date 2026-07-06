class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> result;
        int max = candies[0];
        for(int i=0;i<candies.size();i++){
            if(candies[i]>max){
                max = candies[i];
            }
        }
        
        bool ans;
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=max){
                ans = true;
                result.push_back(ans);
            }
            else{
                ans = false;
                result.push_back(ans);
            }
            
        }
        return result;
        
    }
};