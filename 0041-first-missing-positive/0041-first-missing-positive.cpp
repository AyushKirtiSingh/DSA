class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s1;

        for(int x: nums){
            s1.insert(x);
        }
        int a = 1;
        while(s1.find(a)!=s1.end()){
            a++;
        }
        return a;

        
    }
};