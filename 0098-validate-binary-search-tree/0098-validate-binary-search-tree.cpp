class Solution {
public:
    bool isbst(TreeNode* root,TreeNode* min,TreeNode* max){
        // NULL node → valid BST
        if(root==NULL){
            return true;
        }

        // Current node ko minimum allowed value se compare
        if(min!=NULL && root->val <= min->val){
            return false;
        }

        // Current node ko maximum allowed value se compare
        if(max!=NULL && root->val >= max->val){
            return false;
        }

        // Left subtree: upper limit current node
        // Right subtree: lower limit current node
        return isbst(root->left,min,root) && isbst(root->right,root,max);
    }

    bool isValidBST(TreeNode* root) {
        // Initially koi min/max restriction nahi hai
        return isbst(root,NULL,NULL);
    }
};