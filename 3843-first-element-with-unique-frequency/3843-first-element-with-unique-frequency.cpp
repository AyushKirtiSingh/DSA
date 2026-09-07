class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> m;

        // Har element ki frequency count kar rahe hain
        for(int x : nums){
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                m[x]++;
            }
        }

        unordered_map<int,int> f;

        // Har frequency kitne elements ki hai, wo count kar rahe hain
        for(auto it : m){
            if(f.find(it.second)==f.end()){
                f[it.second] = 1;
            }
            else{
                f[it.second]++;
            }
        }

        // Original order mein pehla element check kar rahe hain
        // jiska frequency sirf ek element ke paas hai
        for(int i=0;i<nums.size();i++){
            if(f[m[nums[i]]]==1){
                return nums[i];
            }
        }

        // Agar koi valid element nahi mila
        return -1;
    }
};

