class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        // n+2 size rakha hai taaki end+1 index safely handle ho sake
        vector<int> diff(n+2,0);

        for(auto &b : bookings){

            // Booking ka starting aur ending flight
            int start = b[0];
            int end = b[1];

            // Har flight ke liye reserved seats
            int count = b[2];

            // start se seats add karna start hongi
            diff[start] += count;

            // end ke baad seats hat jayengi
            diff[end+1] -= count;
        }

        // Prefix sum se har flight ka actual total seats niklega

        vector<int> result;
        int currsum = 0;

        for(int i=1;i<=n;i++){

            // Ab tak ke saare active bookings ka total
            currsum += diff[i];

            // Current flight ka total seats store karo
            result.push_back(currsum);
        }

        return result;
    }
};