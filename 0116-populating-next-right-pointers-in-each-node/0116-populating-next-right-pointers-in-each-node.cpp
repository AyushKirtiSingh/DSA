class Solution {
public:
    Node* connect(Node* root) {

        // Empty tree ya single node hone par directly return karo
        if(root==NULL || root->left == NULL){
            return root;
        }

        queue <Node*> q;

        q.push(root);  // Root ko queue mein push karo
        q.push(NULL);  // Current level ke end ko mark karne ke liye NULL

        Node* prev = NULL;

        // BFS (Level Order Traversal) se har level ke nodes connect karenge
        while(q.size()>0){
            Node* curr = q.front();
            q.pop();

            if(curr==NULL){

                // Current level complete ho gaya
                // Agar queue empty hai toh traversal finish
                if(q.size()==0){
                    break;
                }

                // Next level ke end ko mark karne ke liye NULL push karo
                q.push(NULL);
            }
            else{

                // Current node ke left aur right children ko queue mein add karo
                if(curr->left!=NULL){
                    q.push(curr->left);
                }

                if(curr->right!=NULL){
                    q.push(curr->right);
                }

                // Previous node ke next pointer ko current node se connect karo
                if(prev!=NULL){
                    prev->next = curr;
                }
            }

            // Current node ko next iteration ke liye previous banao
            prev = curr;

        }

        // Connected tree ka root return karo
        return root;
    }
};