class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0;
        int totalcost = 0;
        int start = 0;
        int currgas = 0;

        for(int i=0;i<gas.size();i++){
            totalcost += cost[i];
            totalgas += gas[i];
        }

        if(totalgas<totalcost){
            return -1;
        }
        else{
            for(int i=0;i<gas.size();i++){
                currgas += (gas[i]-cost[i]);
                if(currgas<0){
                    currgas = 0;
                    start = i+1;
                }    
            }
        }

        return start;
    }
};