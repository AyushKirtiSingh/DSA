class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        do{
            slow = nums[slow];      //(slow = slow + 1)
            fast = nums[nums[fast]];  //(fast = fast + 2)
        } while(slow!=fast);

        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];     //(slow = slow+1)
            fast = nums[fast];     //(fast = fast+1)
        }

        return slow;
        
    }
};