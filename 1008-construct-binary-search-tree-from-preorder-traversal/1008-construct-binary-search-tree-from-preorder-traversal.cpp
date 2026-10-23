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
    TreeNode* build(vector<int> &preorder,int &i,int bound){
        // Agar preorder khatam ho gaya ya current value ki limit cross ho gayi,
        // toh is subtree mein koi node nahi banegi.
        if(i>=preorder.size() || preorder[i]>bound){
            return NULL;             // TIME COMPLEXITY : O(n)
        }

        // Current preorder value se node banao.
        TreeNode* root = new TreeNode(preorder[i]);

        // Next element par move karo, taaki har value ek baar process ho.
        i++;

        // Left subtree mein values root->val se chhoti ya barabar bound tak hongi.
        root->left = build(preorder,i,root->val);

        // Right subtree mein values parent ki existing bound ke andar hongi.
        root->right = build(preorder,i,bound);

        // Current subtree ka root return karo.
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Index 0 se start karo.
        int i = 0;

        // Initial bound INT_MAX hai, taaki starting value par upper limit na lage.
        return build(preorder,i,INT_MAX);
    }
};