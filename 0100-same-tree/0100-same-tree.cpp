/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){ //this is the base case if both are null or any one root is null 
            return p==q;
        }

        bool leftsame = isSameTree(p->left,q->left);   //checks left subtree is identical or not
        bool rightsame = isSameTree(p->right,q->right);  //checks right subtree identical or not

        return leftsame && rightsame && p->val == q->val;  //final return true if all these are true left and right subtree are identical and root ka value dono ka same ho
    }
};