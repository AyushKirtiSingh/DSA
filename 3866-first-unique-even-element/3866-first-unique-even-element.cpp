class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> m;

        for(int x : nums){
            if(x%2==0){
                if(m.find(x)==m.end()){
                    m[x]=1;
                }
                else{
                    m[x]++;
                }
            }
                
        }

        for(int x : nums){
            if(m.find(x)!=m.end() && m[x]==1){
                return x;
            }
        }
        return -1;
        
    }
};