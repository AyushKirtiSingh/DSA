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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1;

        if(root==NULL){
            return 0;
        }

        q.push(root);
        q.push(NULL);

        while(q.size()>0){
            TreeNode* curr = q.front();
            q.pop();

            if(curr==NULL){
                if(!q.empty()){
                    level++;
                    q.push(NULL);
                    continue;
                }
                else{
                    break;
                }
            }

            if(curr->left==NULL && curr->right==NULL){
                return level;
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }

        return 0;
    }
};