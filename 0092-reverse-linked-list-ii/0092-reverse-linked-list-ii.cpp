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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // curr ko head se start kar rahe hain
        // iska use left position tak pahunchne ke liye hoga
        ListNode* curr = head;

        // prev curr se just pehle wale node ko track karega
        // starting mein curr se pehle koi node nahi hai
        ListNode* prev = NULL;

        // next ko temporary next node store karne ke liye use karenge
        // taaki link reverse karte time next node lost na ho
        ListNode* next = NULL;

        // Linked List ki positions 1 se start hoti hain
        int idx = 1;


        // curr ko left position wale node tak le jao
        // saath mein prev ko curr se ek node peeche rakho
        while(idx != left) {

            // current node ko prev mein save karo
            prev = curr;

            // position ko aage badhao
            idx++;

            // curr ko next node par move karo
            curr = curr->next;
        }


        // curr ab left position wale node par hai
        // reversal ke baad ye node reversed part ka last node banega
        ListNode* leftnode = curr;

        // left se just pehle wala node save kar rahe hain
        // baad mein reversed part ko isse connect karenge
        ListNode* beforeleftnode = prev;


        // left se right tak nodes ko reverse karo
        while(idx <= right) {

            // next node ko pehle save kar lo
            // warna curr->next change karne par next node lose ho jayega
            next = curr->next;

            // current node ka link reverse karo
            // curr ab previous node ki taraf point karega
            curr->next = prev;

            // prev ko ek step aage le jao
            // ab prev reversed part ka head hai
            prev = curr;

            // curr ko next node par move karo
            curr = next;

            // position ko ek step aage badhao
            idx++;
        }


        // Agar left = 1 tha
        // toh reversed part ka head hi poori list ka new head hoga
        if(beforeleftnode == NULL) {
            head = prev;
        }

        else {
            // left se pehle wale node ko
            // reversed part ke new head se connect karo
            beforeleftnode->next = prev;
        }


        // leftnode reversal se pehle first node tha
        // reversal ke baad ye reversed part ka last node ban gaya
        // isliye ise right ke baad wale node se connect karo
        leftnode->next = curr;


        // Modified linked list ka head return karo
        return head;
    }
};


// left tak jao → left se right reverse karo → dono sides ko reconnect karo