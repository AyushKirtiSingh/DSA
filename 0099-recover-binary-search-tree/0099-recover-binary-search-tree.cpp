class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    // Inorder traversal se BST ke nodes increasing order mein milte hain
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }

        inorder(root->left);

        // Previous node ki value current node se badi hai,
        // toh inorder sequence mein violation mila hai
        if(prev!=NULL && prev->val > root->val){

            // First violation par previous node incorrect node hoga
            if(first==NULL){
                first = prev;
            }

            // Har violation par current node ko second incorrect node maanenge
            sec = root;
        }

        // Current node ko next comparison ke liye previous bana diya
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        // Dono swapped nodes identify karne ke liye inorder traversal
        inorder(root);

        // Original tree ki structure change kiye bina values swap kar di
        swap(first->val,sec->val);
    }
};