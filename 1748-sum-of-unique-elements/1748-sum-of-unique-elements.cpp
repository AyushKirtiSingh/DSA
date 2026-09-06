class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int x : nums){
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }

        int sum = 0;

        for(auto it : m){
            if(it.second==1){
                sum += it.first;
            }
        }

        return sum;
    }
};