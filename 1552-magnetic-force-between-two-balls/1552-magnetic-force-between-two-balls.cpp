class Solution {
public:
    bool allowedPosition(vector<int>& position, int m, int minallowedposition){
        sort(position.begin(),position.end());
        int place = position[0];
        int balls = 1;
        int n = position.size();

        for(int i=1;i<n;i++){

            if((position[i] - place) >= minallowedposition){
                balls++;
                place = position[i];
            }
            if(balls==m){
                return true;
            }

        }
        return false;
    }
   

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        if(m>n){
            return -1;
        }

        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        for(int i=0;i<n;i++){
            maxVal = max(maxVal,position[i]);
            minVal = min(minVal,position[i]);
        }

        int st = 0, end = maxVal - minVal;
        int ans = -1;

        while(st<=end){
            int mid = st + (end - st)/2;

            if(allowedPosition(position,m,mid)){
                ans = mid;
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
        
    }
};