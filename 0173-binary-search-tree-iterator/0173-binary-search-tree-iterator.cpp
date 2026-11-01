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
class BSTIterator {
public:
    stack<TreeNode*> s;

    // Leftmost node tak ke saare nodes stack mein store karte hain.
    // Isse inorder traversal ka next smallest element top par milta hai.
    void storeleftnodes(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        // Initially root se start karke saare left nodes stack mein push karte hain.
        storeleftnodes(root);
    }

    int next() {   // Amortized T.C: O(1), S.C: O(H)
        // Stack ke top par inorder traversal ka next smallest node hai.
        TreeNode* ans = s.top();
        s.pop();

        // Agar current node ka right subtree hai,
        // toh uske leftmost nodes ko stack mein push karte hain.
        if(ans->right){
            storeleftnodes(ans->right);
        }

        // Current node ki value return karte hain.
        return ans->val;
    }

    bool hasNext() {
        // Stack empty nahi hai toh next element available hai.
        return s.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


 // TIME COMPLEXITY:
// Constructor: O(H) - Initially leftmost path stack mein store hota hai.
// next(): O(1) amortized - Har node exactly ek baar push aur pop hota hai.
// hasNext(): O(1) - Stack empty hai ya nahi, bas check karte hain.

// SPACE COMPLEXITY:
// O(H) - Stack mein maximum tree ki height ke nodes store ho sakte hain.
// H = Height of the BST.