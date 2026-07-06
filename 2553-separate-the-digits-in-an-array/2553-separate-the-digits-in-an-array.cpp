class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector <int> answer;
        for(int i=0;i<nums.size();i++){
            string str = to_string(nums[i]);
            for(int i=0;i<str.length();i++){
                char ch = str[i] - '0';
                answer.push_back(ch);
                
            }
        }
        return answer;
        
    }
};