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
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* curr = head;

        while(curr!=NULL){
            size++;              //this is used in calculating the size of the linked list
            curr = curr->next;
        }
        int mid = 0;

        if(size%2!=0){
            mid = (size/2);
        }                    //it gives the middle index of the linked list acc to question it is same for both even or odd size
        else{
            mid = (size/2);
        }

        ListNode* temp = head;
        int idx = 0;

        while(idx!=mid){
            temp = temp->next;    //traverse temp till idx becomes mid means temp will traversed till mid
            idx++;
        }

        return temp;   //as temp is the new head and position same as mid thats why we return temp
        
    }
};