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

    // Previous processed node ko store karega
    // Isi se current node ka right pointer connect hoga
    TreeNode* nextright = NULL;

    void flatten(TreeNode* root) {

        // Tree empty hai toh kuch nahi karna
        if(root==NULL){
            return;
        }

        // Right subtree ko pehle process karte hain
        flatten(root->right);

        // Phir left subtree ko process karte hain
        flatten(root->left);

        // Flattened tree mein left pointer hamesha NULL hoga
        root->left = NULL;

        // Current node ko previously processed node ke aage connect karo
        root->right = nextright;

        // Current node ab next processed node ban gaya
        nextright = root;
    }
};