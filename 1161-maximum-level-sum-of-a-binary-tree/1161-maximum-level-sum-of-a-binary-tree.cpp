class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        map<int,int> m;

        int maxval = INT_MIN;  // Ab tak ka maximum level sum
        int level = 0;         // Current level number
        int sum = 0;           // Current level ka total sum
        int temp = INT_MIN;    // Previous maximum sum

        q.push(root);
        q.push(NULL);          // NULL = current level khatam

        while(q.size()>0){
            TreeNode* curr = q.front();
            q.pop();

            if(curr==NULL){

                if(!q.empty()){
                    // Ek level complete ho gaya

                    temp = maxval;

                    // Current level ke sum ko maximum se compare karo
                    maxval = max(sum,maxval);

                    level++;

                    // Agar naya maximum mila, toh uski level store karo
                    if(maxval>temp){
                        m[maxval] = level;
                    }

                    sum = 0;       // Next level ke liye sum reset
                    q.push(NULL);  // Next level ka end mark karo

                    continue;
                }

                else{
                    // Ye last level ka NULL hai,
                    // isliye last level ka sum ab process karna hai
                    //last wala level ka pura sum nikalne par queue khali ho jata hai toh break karne se pehle ek last baar maxval ko update karne ka process karte hai kya pta last level mein hi ans ho issiliye

                    temp = maxval;

                    maxval = max(sum,maxval);

                    level++;

                    // Agar last level ka sum maximum hai
                    if(maxval>temp){
                        m[maxval] = level;
                    }

                    break;
                }
            }

            // Current node ki value current level ke sum mein add
            sum += curr->val;

            // Left child ko queue mein daalo
            if(curr->left!=NULL){
                q.push(curr->left);
            }

            // Right child ko queue mein daalo
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }

        // Maximum sum wali level return karo
        return m[maxval];
    }
};