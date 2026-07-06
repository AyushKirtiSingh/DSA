class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> s1;
        vector <int> result;

        for(int val : nums){
            s1.insert(val);
        }

        int count = 1;

        for(int x : s1){
            result.push_back(x);
        }
        int maxCount = 1;

        for(int i=1;i<result.size();i++){
            if(result[i] - result[i-1]==1){
                count++;
                maxCount = max(maxCount,count);
            }
            else{
                count = 1;
            }
            
        }
        if(nums.size()==0){
            maxCount = 0;
        }
        return maxCount;

        
    }
};