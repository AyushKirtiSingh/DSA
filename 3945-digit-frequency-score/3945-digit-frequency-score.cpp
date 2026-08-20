class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> m;
        while(n!=0){
            int digit = n % 10;
            n = n/10;
            if(m.find(digit)==m.end()){
                m[digit] = 1;
            }
            else{
                m[digit]++;
            }
        }
        int ans = 0;

        for(auto it : m){
            ans += it.first * it.second;
        }

        return ans;
    }
};