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
class Solution {     //TC : O(n+m) & SC : O(n+m)
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        // Agar first list khatam ho gayi,
        // toh second list ke saare remaining nodes already sorted hain.
        if(head1 == NULL)
            return head2;

        // Agar second list khatam ho gayi,
        // toh first list ke remaining nodes return kar do.
        if(head2 == NULL)
            return head1;


        // Dono current nodes mein se jo chhota hai,
        // wahi merged list mein pehle aayega.
        if(head1->val <= head2->val) {

            // head1 ko current answer ka node maan liya.
            //
            // Ab question hai:
            // "head1 ke BAAD kaunsa node aayega?"
            //
            // Iske liye remaining lists:
            // head1->next aur head2 ko merge karenge.
            //
            // IMPORTANT:
            // Recursive call ka result turant nahi milta.
            // Ye call stack mein temporarily store hoti hai.
            //
            // Example:
            // merge(1,2)
            //   ↓
            // merge(3,2)
            //   ↓
            // merge(3,4)
            //
            // Har call wait karti hai ki neeche wali
            // recursive call kya return karegi.
            head1->next = mergeTwoLists(head1->next, head2);

            // Jab recursion neeche tak pahunch kar
            // base case hit karti hai, tab calls reverse order
            // mein wapas aati hain.
            //
            // Jo merged list recursive call ne return ki,
            // usko head1 ke next se connect kar diya gaya.
            //
            // Ab head1 poori merged list ka starting node hai.
            return head1;
        }

        else {

            // head2 chhota hai, toh head2 answer ka current node hoga.
            //
            // Ab head2 ke baad kya aayega?
            // head1 aur head2->next ki remaining lists ko merge karo.
            //
            // Ye recursive call bhi call stack mein temporarily
            // wait karegi jab tak remaining lists merge nahi ho jaati.
            head2->next = mergeTwoLists(head1, head2->next);

            // Recursion se merged remaining list return hone ke baad
            // usko head2 ke next se connect kar diya.
            //
            // Ab head2 merged list ka starting node hai.
            return head2;
        }
    }
};