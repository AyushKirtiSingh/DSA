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
        int size = 0;
        ListNode* curr = head;

        while(curr != NULL){
            curr = curr->next;
            size++;
        }
        if(size==1){
            return NULL;
        }
        int idx = size - n;
        if(idx==0)return head->next;

        int i = 1;
        ListNode* temp = head->next;
        ListNode* prev = head;
        while(i!=idx){
            i++;
            prev = prev->next;
            temp = temp->next;
            
        }

        prev->next = prev->next->next;
        temp->next = NULL;
        delete temp;

        return head;

        
    }
};