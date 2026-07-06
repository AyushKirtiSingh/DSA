class Solution {
public:
    int minElement(vector<int>& nums) {
        vector <int> result;
        
        for(int i=0;i<nums.size();i++){
            int ans = 0;
            string str = to_string(nums[i]);
            for(int i=0;i<str.length();i++){
                char ch = str[i];
                int num = ch - '0';
                ans += num;
            }
            result.push_back(ans);    
        }
        
            
        int min = result[0];
        for(int i=0;i<result.size();i++){
            if(result[i]<min){
                min = result[i];
            }
        }
        return min;
        
    }
};