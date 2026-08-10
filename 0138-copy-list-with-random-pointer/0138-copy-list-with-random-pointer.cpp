/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // Edge case
        if(head == NULL){
            return NULL;
        }

        // Original node ko uske copied node se map karenge
        unordered_map<Node*, Node*> m;

        // Pehla copied node create kiya
        Node* newhead = new Node(head->val);      // TIME COMPLEXITY : O(n)
                                                
        Node* oldtemp = head->next;
        Node* newtemp = newhead;

        // First node ki mapping store ki
        m[head] = newhead;

        // Saare remaining nodes ko copy karna
        while(oldtemp != NULL){

            Node* copynode = new Node(oldtemp->val);

            // Original node → Copied node mapping
            m[oldtemp] = copynode;

            // Copied list mein node attach karo
            newtemp->next = copynode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        // Dono pointers ko list ke start par reset kiya
        oldtemp = head;
        newtemp = newhead;

        // Ab random pointers connect karenge
        while(oldtemp != NULL){

            // Original random jis node par hai,
            // map se uska copied node nikaal lo
            newtemp->random = m[oldtemp->random];

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newhead;
    }
};