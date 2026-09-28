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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        unsigned long long maxwidth = 0;

        while(q.size()>0){
            unsigned long long currsize = q.size();
            unsigned long long stidx = q.front().second;
            unsigned long long endidx = q.back().second;

            unsigned long long currwidth = (endidx-stidx)+1;

            maxwidth = max(maxwidth,currwidth);

            for(int i=0;i<currsize;i++){
                auto curr = q.front();
                q.pop();
                if(curr.first->left!=NULL){
                    q.push({curr.first->left,(2*curr.second)+1});
                }

                if(curr.first->right!=NULL){
                    q.push({curr.first->right,(2*curr.second)+2});
                }
            }
        }

        return maxwidth;
    }
};