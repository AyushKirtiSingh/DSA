class Solution {
public:
    vector<TreeNode*> ans1;

    // Inorder traversal karke original nodes ke addresses store karenge
    void inorder(TreeNode* root,vector<TreeNode*> &ans){
        if(root==NULL){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root);  // Current node ka address store kiya
        inorder(root->right,ans);
    }


    void recoverTree(TreeNode* root) {
        vector<int> ans2;

        inorder(root,ans1);  // BST ke nodes ko inorder sequence mein store kiya

        // Original nodes ki values ko separate array mein copy kiya
        for(auto x : ans1){
            ans2.push_back(x->val);
        }

        sort(ans2.begin(),ans2.end());  // Correct BST ki sorted inorder sequence banayi

        vector<int> index;

        // Original aur sorted sequence compare karke wrong nodes ke index find kiye
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]->val!=ans2[i]){
                index.push_back(i);
            }
        }

        // Dono incorrect nodes ki values swap karke original BST recover kiya
        swap(ans1[index[0]]->val,ans1[index[1]]->val);
    }
};