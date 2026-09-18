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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        map<int,int> m;
        int maxval = INT_MIN;
        int level = 0;
        int sum = 0;
        int temp = INT_MIN;

        q.push(root);
        q.push(NULL);

        while(q.size()>0){
            TreeNode* curr = q.front();
            q.pop();

            if(curr==NULL){
                if(!q.empty()){
                    temp = maxval;
                    
                    maxval = max(sum,maxval);
                    
                    level++;

                    if(maxval>temp){
                        m[maxval] = level;
                    }
                

                    
                    
                    sum = 0;
                    q.push(NULL);
                    continue;
                }
                else{
                    temp = maxval;
                    
                    maxval = max(sum,maxval);
                    
                    level++;

                    if(maxval>temp){
                        m[maxval] = level;
                    }
                    break;
                }
            }

            sum += curr->val;

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }


        }

        return m[maxval];
    }
};