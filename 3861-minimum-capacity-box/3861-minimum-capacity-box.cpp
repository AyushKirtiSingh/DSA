class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int min = INT_MAX;
        vector<int> result;
        int idx = 0;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize && capacity[i]<min){
                min = capacity[i];
                idx = i;
                result.push_back(capacity[i]);
            }
        }
        if(result.size()==0){
            return -1;
        }
        else{
            return idx;
        }
        
    }
};