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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;   // Previous node initially NULL
        ListNode* curr = head;   // Current node head se start
        ListNode* next = NULL;   // Next node ko temporarily store karega

        while(curr != NULL) {

            next = curr->next;   // Pehle next node ko save karo

            curr->next = prev;   // Current node ka link reverse karo

            prev = curr;         // Prev ko current node par move karo
            curr = next;         // Curr ko next node par move karo
        }

        return prev;             // Prev ab new head hai
    }
};