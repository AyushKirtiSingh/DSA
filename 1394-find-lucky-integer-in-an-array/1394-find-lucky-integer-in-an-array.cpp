class Solution {
public:
    int findLucky(vector<int>& arr) {
        int count[501];
        //count.size(501);
        for(int i : arr){
            count[i]++;
        }
        for(int i=500;i>0;i--){
            if(i==count[i]){
                return i;
            }
        }
        return -1;
        
    }
};