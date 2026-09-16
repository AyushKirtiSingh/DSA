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

    // Ye function check karta hai ki dono trees EXACTLY same hain ya nahi
    bool same(TreeNode* root, TreeNode* subRoot){

        // Dono NULL hain → same
        // Ek NULL hai aur doosra nahi → different
        if(root==NULL || subRoot==NULL){
            return root==subRoot;
        }

        // Left subtree ko recursively compare karo
        bool leftsame = same(root->left,subRoot->left);

        // Right subtree ko recursively compare karo
        bool rightsame = same(root->right,subRoot->right);

        // Current node ki value bhi same honi chahiye
        // + left subtree same
        // + right subtree same
        return leftsame && rightsame && root->val == subRoot->val;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Dono NULL → same
        // Ek NULL → subtree nahi ban sakta
        if(root==NULL || subRoot==NULL){
            return root == subRoot;
        }

        // Pehle current node ki value match karo
        // Value match ho toh poora tree 'same()' se check karo
        if(root->val==subRoot->val && same(root,subRoot)){
            return true;
        }

        // Current node par match nahi mila
        // Toh left ya right subtree mein search karo
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};