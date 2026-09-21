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

    // Inorder mein current root ki position find karo
    // Is position se left aur right subtree separate honge
    int search(vector<int>& inorder,int val,int left,int right){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }

        return -1;
    }

    // preIdx ko reference se pass karna zaroori hai
    // taaki recursion ke across same index continuously update ho
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preIdx,int left,int right){

        // Agar range invalid hai → subtree exist nahi karta
        if(left>right){
            return NULL;
        }

        // Preorder ka current element root banega
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Inorder mein root ki position find karo
        // Root ke left mein → left subtree
        // Root ke right mein → right subtree
        int inidx = search(inorder,preorder[preIdx],left,right);

        // Next preorder element next subtree ka root hoga
        preIdx++;

        // Inorder ke root ke left wale elements se left subtree banao
        root->left = helper(preorder,inorder,preIdx,left,inidx-1);

        // Inorder ke root ke right wale elements se right subtree banao
        root->right = helper(preorder,inorder,preIdx,inidx+1,right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        // Puri inorder range se tree construct karo
        return helper(preorder,inorder,preIdx,0,inorder.size()-1);
    }
};


// Preorder → Root batata hai
//               ↓
// Inorder → Root ki position batata hai
//               ↓
//        ┌──────┴──────┐
//        ↓             ↓
//    Left subtree   Right subtree