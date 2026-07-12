class Solution {
public:
    bool isPossible(vector<int>& price, int k, int minallowed){
        //sort(price.begin(),price.end());
        int candies = 1;
        int tastiness = price[0];
        int n = price.size();

        for(int i=1;i<n;i++){
            if(price[i] - tastiness >= minallowed){
                candies++;
                tastiness = price[i];
            }
            if(candies==k){
                return true;
            }

        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(),price.end());
        int st = 0, end = price[n-1] - price[0];
        int ans = -1;

        while(st<=end){
            int mid = st + (end -st)/2;

            if(isPossible(price,k,mid)){
                ans = mid;
                st = mid + 1;
            }
            else{
                end = mid -1;
            }
        }
        return ans;
    }
};