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
    // Root se current node tak ka path recursively build karta hai
    void allpaths(TreeNode* root, string path, vector<string> &ans){

        // Agar leaf node hai, toh complete path answer mein store karo
        if(root->left==NULL && root->right==NULL){
            ans.push_back(path);
            return;
        }

        // Left subtree mein jaakar current path mein left node add karo
        if(root->left){
            allpaths(root->left,path+"->"+to_string(root->left->val),ans);
        }

        // Right subtree mein jaakar current path mein right node add karo
        if(root->right){
            allpaths(root->right,path+"->"+to_string(root->right->val),ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        // Saare root-to-leaf paths store karne ke liye
        vector<string> ans;

        // Path ko root node se initialize karo
        string path = to_string(root->val);

        // Root se DFS start karo
        allpaths(root,path,ans);

        return ans;
    }
};

/*
Time Complexity: O(N * H)
- N nodes traverse hote hain.
- Har path banate waqt string copying/concatenation ki wajah se
  path length H tak ho sakti hai.
- Balanced tree mein H = log N, skewed tree mein H = N.

Space Complexity: O(N * H)
- Answer mein root-to-leaf paths store hote hain.
- Recursion stack: O(H).
*/

