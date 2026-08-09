/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {     //SC:O(1) & TC:O(n)

        // Slow pointer ek-ek node move karega
        ListNode* slow = head;

        // Fast pointer ek baar mein do nodes move karega
        ListNode* fast = head;

        // Jab tak fast end tak nahi pahunchta,
        // slow aur fast ko move karte rahenge
        while(fast != NULL && fast->next != NULL) {

            // Slow 1 step aage jayega
            slow = slow->next;

            // Fast 2 steps aage jayega
            fast = fast->next->next;
        }

        // Jab fast end par pahunch jayega,
        // slow middle node par hoga
        return slow;
    }
};