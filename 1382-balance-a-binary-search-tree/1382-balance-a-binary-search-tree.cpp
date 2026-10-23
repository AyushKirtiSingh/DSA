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
    void inorder(TreeNode* root,vector<int> &arr){
        if(root==NULL){
            return;
        }

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanced(vector<int> &arr,int st, int end){
        if(st > end){
            return NULL;
        }

        int mid = st + (end-st)/2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = balanced(arr,st,mid-1);

        root->right = balanced(arr,mid+1,end);

        return root;

    }
    vector<int> temp;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root,temp);

        return balanced(temp,0,temp.size()-1);
    }
};