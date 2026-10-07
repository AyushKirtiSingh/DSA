class Solution {
public:
    TreeNode * prev = NULL;

    int minDiffInBST(TreeNode* root) {
        // NULL node → koi difference nahi, maximum value return
        if(root==NULL){
            return INT_MAX;
        }

        int ans = INT_MAX;

        // Inorder: pehle left subtree
        if(root->left){
            int leftmin = minDiffInBST(root->left);
            ans = min(ans,leftmin);
        }

        // Current node ko previous inorder node se compare
        if(prev != NULL){
            ans = min(ans,root->val-prev->val);
        }

        // Current node ab next node ke liye previous banega
        prev = root;

        // Inorder: ab right subtree
        if(root->right){
            int rightmin = minDiffInBST(root->right);
            ans = min(ans,rightmin);
        }

        // Current subtree ka minimum difference
        return ans;
    }
};

// Tree:
//         4
//        / \
//       2   6
//      / \   \
//     1   3   7

// Inorder: 1 → 2 → 3 → 4 → 6 → 7

// prev = NULL, ans = INT_MAX

// 1 → prev=NULL → no comparison → prev=1
// 2 → 2-1=1 → ans=1 → prev=2
// 3 → 3-2=1 → ans=1 → prev=3
// 4 → 4-3=1 → ans=1 → prev=4
// 6 → 6-4=2 → ans=1 → prev=6
// 7 → 7-6=1 → ans=1 → prev=7

// Final Answer = 1

// Flow:
// Inorder → previous node store → current-prev → minimum difference