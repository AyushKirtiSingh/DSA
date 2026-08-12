class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {

        // Number -> frequency store karenge
        unordered_map<int,int> m;

        int count = 0;

        for(int x : nums){
            m[x]++;

            // Check if at least one even number exists
            if(x % 2 == 0)
                count++;
        }

        // Agar koi even number nahi hai
        if(count == 0)
            return -1;

        // Map ke key-value pairs ko vector mein store karenge
        vector<pair<int,int>> v;

        for(auto &it : m){
            v.push_back({it.first, it.second});
        }

        // maxval = highest frequency
        // minval = answer (smallest number in case of tie)
        int maxval = INT_MIN;
        int minval = INT_MAX;

        for(int i = 0; i < v.size(); i++){

            // Sirf even numbers consider karo
            if(v[i].first % 2 == 0){

                // Higher frequency mila
                if(v[i].second > maxval){
                    maxval = v[i].second;
                    minval = v[i].first;
                }

                // Same frequency → smaller number choose karo
                else if(v[i].second == maxval){
                    minval = min(v[i].first, minval);
                }
            }
        }

        return minval;
    }
};