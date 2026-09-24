class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int target1 = intervals[i][1];
            int target2 = intervals[i][0];
            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<=target1 && intervals[j][1]>=target2){
                    count++;
                }
            }
        }

        return count;
    }
};