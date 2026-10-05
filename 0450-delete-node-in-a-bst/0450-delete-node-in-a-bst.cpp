// Key chhoti → LEFT
// Key badi   → RIGHT

// Node mil gayi:
// 0/1 child → child return
// 2 children → Inorder Successor
//            → value copy
//            → successor delete


class Solution {
public:
    // Right subtree ka leftmost node = inorder successor
    TreeNode* getinordersuccessor(TreeNode* root) {
        while(root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Node nahi mili
        if(root == NULL)
            return NULL;

        // Key chhoti → left jao
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }

        // Key badi → right jao
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        // Node mil gayi
        else {

            // Left child nahi → right child return
            if(root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Right child nahi → left child return
            else if(root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Dono children hain
            else {
                // Successor = right subtree ka leftmost
                TreeNode* IS = getinordersuccessor(root->right);

                // Successor ki value copy karo
                root->val = IS->val;

                // Original successor ko delete karo
                root->right = deleteNode(root->right, IS->val);
            }
        }

        return root;
    }
};