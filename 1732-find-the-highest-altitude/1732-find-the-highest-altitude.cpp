class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> result;

        for(int i=0;i<=n;i++){
            int k = 0;
            for(int j=0;j<i;j++){
                if(i==0){
                    k = 0;
                }
                else{
                    k += gain[j];
                }

            }
            result.push_back(k);
        }
        int max = INT_MIN;
        for(int i=0;i<result.size();i++){
            if(result[i]>max){
                max = result[i];
            }
        }
        return max;
        
    }
};