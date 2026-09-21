class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2,0);  //to avoid the edge case index of end +1 we take size n+2

        for(auto &b : bookings){
            int start = b[0];      // difference array technique standard approach
                                   // line sweep technique
            int end = b[1];
            int count = b[2];


            diff[start] += count;
            diff[end+1] -= count;
        }

        //result store commulative sum

        vector<int> result;
        int currsum = 0;
        for(int i=1;i<=n;i++){
            currsum += diff[i];
            result.push_back(currsum);
        }

        return result;
    }
};