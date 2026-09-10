class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {   //O(n)
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        //1st window
        
        for(int i=0;i<k;i++){   //O(k)
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i=k;i<n;i++){   //O(n-k)
            ans.push_back(nums[dq.front()]);

            //Remove the elements that are not part of curr window
            while(dq.size()>0 && dq.front()<=i-k){
                dq.pop_front();
            }

            //Remove the smaller values
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

        }

        ans.push_back(nums[dq.front()]);

        return ans;

        
        
    }
};