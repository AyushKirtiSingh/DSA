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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>>ans;
        vector<int> result;

        if(root==NULL){
            return {};
        }

        q.push(root);
        q.push(NULL);

        while(q.size()>0){
            TreeNode* curr = q.front();
            q.pop();

            if(curr==NULL){
                if(!q.empty()){
                    ans.push_back(result);
                    result.clear();
                    q.push(NULL);
                    continue;
                }
                else{
                    ans.push_back(result);   //ye last stage ke level ke lements add karne ke liye zaroori hai normally zaroorat nhi hoti kyunki usmein bas endl add karna hota hai aur wo last ke stage mein naa bhi lge toh sirf break se ho jayega but yha push karna hai issiliye zaroori h
                    break;
                }
            }

            result.push_back(curr->val);

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }

        return ans;
    }
};