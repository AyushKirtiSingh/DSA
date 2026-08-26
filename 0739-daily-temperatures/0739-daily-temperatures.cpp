class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        vector<int> ans(nums.size(),0);
        stack<int> s;

        for(int i=0;i<nums.size();i++){
            while(s.size()>0 && nums[s.top()]<=nums[i]){
                s.pop();          //removing elements if it is less than the current vec elements from stack
            }

            if(s.size()==0){    //stack when empty there will be no future day
                ans[i] = 0;
            }
            else{
                ans[i] = i - s.top();   //else condition when there will be some days left
            }

            s.push(i);    //pushing every i for further checking
        }

        reverse(ans.begin(),ans.end()); //reversing the ans to cancel the effect of initial rev

        return ans;

    }
};