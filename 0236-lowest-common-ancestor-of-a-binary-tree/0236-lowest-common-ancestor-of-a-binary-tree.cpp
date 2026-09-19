/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Agar root NULL hai, matlab is subtree mein p ya q nahi mila.
        // Isliye NULL return karenge.
        if(root==NULL){
            return NULL;
        }

        // Agar current root hi p ya q hai,
        // toh is node ko return kar denge.
        //
        // Ye important hai kyunki ab humein iske neeche
        // further search karne ki zarurat nahi hai.
        if(root->val==p->val || root->val==q->val){
            return root;
        }


        // Current root p/q nahi hai, toh dono subtrees mein search karenge.
        //
        // left recursion complete hone ke baad jo value return hogi,
        // woh left variable mein store hogi.
        //
        // Example:
        // Agar left subtree mein p mil gaya, toh left mein p ka node aayega.
        TreeNode* left = lowestCommonAncestor(root->left,p,q);

        // Same tarah right subtree mein search karenge.
        // Agar right subtree mein q mil gaya, toh right mein q ka node aayega.
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // Ab recursion neeche jaakar wapas aa chuki hai.
        // Yahin se actual BACKTRACKING samajhni hai.
        //
        // Agar left aur right dono NULL nahi hain,
        // iska matlab p aur q dono different subtrees mein mile hain.
        //
        // Is case mein current root hi dono ka Lowest Common Ancestor hoga.
        //
        // Example:
        //        3
        //       / \
        //      5   1
        //
        // left = 5
        // right = 1
        // => dono mile, toh 3 LCA hai.
        if(left!=NULL && right!=NULL){
            return root;
        }

        // Agar sirf left NULL nahi hai,
        // iska matlab p/q mein se koi ek left subtree mein mila hai
        // aur right subtree se kuch nahi mila.
        //
        // Current root abhi LCA nahi hai,
        // isliye left se jo node mila tha usko upar return kar denge.
        //
        // Ye returned value parent node tak backtrack hoti rahegi.
        else if(left != NULL)
           return left;

        // Agar left mein kuch nahi mila,
        // toh jo bhi result right subtree se aaya hai,
        // wahi parent ko return kar denge.
        //
        // Agar right bhi NULL hai, toh NULL hi return hoga.
        else
           return right;
        

        

    }
};