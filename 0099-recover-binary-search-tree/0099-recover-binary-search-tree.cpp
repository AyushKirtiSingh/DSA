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
    vector<TreeNode*> ans1;
    
    void inorder(TreeNode* root,vector<TreeNode*> &ans){
        if(root==NULL){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root);
        inorder(root->right,ans);
    }

    
    void recoverTree(TreeNode* root) {
        vector<int> ans2;
        inorder(root,ans1);

        for(auto x : ans1){
            ans2.push_back(x->val);
        }

        sort(ans2.begin(),ans2.end());
        vector<int> index;

        for(int i=0;i<ans1.size();i++){
            if(ans1[i]->val!=ans2[i]){
                index.push_back(i);
            }
        }

        swap(ans1[index[0]]->val,ans1[index[1]]->val);
    }
};