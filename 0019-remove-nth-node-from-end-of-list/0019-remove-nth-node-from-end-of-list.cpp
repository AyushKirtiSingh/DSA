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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Pehle linked list ka size find kar rahe hain
        int size = 0;
        ListNode* curr = head;

        while(curr != NULL) {
            curr = curr->next;
            size++;
        }

        // Agar sirf ek node hai, toh wahi remove hogi
        if(size == 1) {
            return NULL;
        }

        // Nth node from end ka index from beginning
        int idx = size - n;

        // Agar first node remove karni hai
        if(idx == 0)
            return head->next;

        // prev = delete hone wale node se pehle wala node
        // temp = delete hone wala node
        int i = 1;
        ListNode* temp = head->next;
        ListNode* prev = head;

        // Required position tak pointers move karo
        while(i != idx) {
            i++;
            prev = prev->next;
            temp = temp->next;
        }

        // Node ko list se remove karo
        prev->next = prev->next->next;

        // Removed node ko safely disconnect karo
        temp->next = NULL;

        // Memory free karo
        delete temp;

        return head;
    }
};