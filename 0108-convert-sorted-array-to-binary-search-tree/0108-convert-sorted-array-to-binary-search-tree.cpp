class Solution {
public:
    // Middle element ko root banakar balanced BST banate hain
    TreeNode* helper(vector<int>& nums, int st, int end) {
        // Range khatam → koi node nahi
        if (st > end) {
            return NULL;
        }

        // Middle element = current subtree ka root
        int mid = st + (end - st) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // Left half se left subtree
        root->left = helper(nums, st, mid - 1);

        // Right half se right subtree
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    // TIME: O(N) | SPACE: O(log N)
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};