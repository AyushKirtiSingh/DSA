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
    ListNode* swapPairs(ListNode* head) {

        // 0 ya 1 node hai toh swap ki zarurat nahi
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* first = head;
        ListNode* sec = head->next;

        while(first != NULL && sec != NULL){

            // Third node ko save karo
            ListNode* third = sec->next;

            // Pair ko swap karo: sec -> first -> third
            sec->next = first;
            first->next = third;

            // Previous pair ko current swapped pair se connect karo
            if(prev != NULL){
                prev->next = sec;
            }
            else{
                // First pair swap hone par head update hoga
                head = sec;
            }

            // Next pair par move karo
            prev = first;
            first = third;

            // Next pair ka second node find karo
            if(third != NULL){
                sec = third->next;
            }
            else{
                sec = NULL;
            }
        }

        return head;
    }
};