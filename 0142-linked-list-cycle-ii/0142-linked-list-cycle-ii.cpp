/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        bool iscycle = false;

        // Slow 1 step, fast 2 steps → cycle hai toh dono milenge
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                iscycle = true;
                break;
            }
        }

        // Fast NULL tak pahunch gaya → cycle nahi hai
        if(!iscycle){
            return NULL;
        }

        // Head aur meeting point se same speed par chalo
        slow = head;

        // Jahan dono milenge wahi cycle ka starting node hai
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};