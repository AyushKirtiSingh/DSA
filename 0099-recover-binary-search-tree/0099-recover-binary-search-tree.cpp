class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* sec = NULL;

        // Morris Inorder Traversal: bina recursion aur stack ke traversal
        while(root!=NULL){
            if(root->left==NULL){

                // Left subtree nahi hai, toh current node visit karo
                // Previous node se compare karke BST violation check karo
                if(prev!=NULL && prev->val > root->val){
                    if(first==NULL){
                        first = prev;  // First violation ka previous node store karo
                    }
                    sec = root;       // Current node second incorrect node ho sakta hai
                }

                prev = root;          // Current node ko next comparison ke liye previous banao
                root = root->right;
            }
            else{
                // Left subtree ka Inorder Predecessor (IP) find karo
                TreeNode* IP = root->left;

                while(IP->right != NULL && IP->right != root){
                    IP = IP->right;
                }

                if(IP->right==NULL){

                    // Temporary thread banao taaki left subtree complete hone ke baad
                    // wapas current node par aa sakein
                    IP->right = root;
                    root = root->left;
                }
                else{

                    // Thread already present hai, matlab left subtree traverse ho chuka hai
                    // Ab current node visit karke previous node se compare karo
                    if(prev!=NULL && prev->val > root->val){
                        if(first==NULL){
                            first = prev;  // First incorrect node identify karo
                        }
                        sec = root;        // Second incorrect node identify/update karo
                    }    

                    prev = root;          // Current node ko previous node banao

                    IP->right = NULL;     // Temporary thread remove karke original tree restore karo
                    root = root->right;   // Right subtree ki taraf move karo
                }
            }
        }

        // Dono incorrect nodes milne par unki values swap karke BST recover karo
        if(first!=NULL && sec!=NULL){
            swap(first->val,sec->val);
        }
    }
};


// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)