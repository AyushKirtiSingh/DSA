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
    ListNode* oddEvenList(ListNode* head) {

        // 0 ya 1 node hai toh already sorted hai
        if(head == NULL || head->next == NULL)
            return head;

        // Odd aur even list ke pointers
        ListNode* odd = head;
        ListNode* even = head->next;

        // Even list ke first node ko save kar liya
        ListNode* temp = even;

        while(even != NULL && even->next != NULL) {

            // Odd node ko next odd node se connect karo
            odd->next = odd->next->next;
            odd = odd->next;

            // Even node ko next even node se connect karo
            even->next = even->next->next;
            even = even->next;
        }

        // Odd list ke end par even list attach karo
        odd->next = temp;

        return head;
    }
};