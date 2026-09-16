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
    int ans = 0;
    int height(TreeNode* root){  //O(n)
    
        if(root==NULL){
            return 0;
        }

        int leftht = height(root->left);
        int rightht = height(root->right);

        ans = max(ans, leftht+rightht);

        return max(leftht,rightht) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {   //Total time complexity: O(N) optimized only using one function not two and not doing recursive calling of diameterofbinarytree funcn.
        height(root);

        return ans;
    }
};