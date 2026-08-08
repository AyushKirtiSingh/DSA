class Solution {
public:
    long long rev(long long n){
        string ans = "";
        string str = to_string(n);
        for(int i=str.length()-1;i>=0;i--){
            ans += str[i];
                
        }
        return stoll(ans);
    }
    
    
    int countNicePairs(vector<int>& nums) {
        const long long MOD = 1000000007;
        long long count = 0;
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i] - rev(nums[i]);
        }
      
        unordered_map<int,int> m;

        for(int x: nums){
            if(m.find(x)==m.end()){
                m[x] = 1;
            }
            else{
                count += m[x];
                m[x]++;
            }
        }
        return (count % MOD);
        
        
    }
};