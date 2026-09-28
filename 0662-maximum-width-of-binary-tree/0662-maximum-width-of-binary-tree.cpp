class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        // Queue mein node + uska virtual index store karenge
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long maxwidth = 0;

        while (!q.empty()) {

            // Current level mein kitne nodes hain
            unsigned long long currsize = q.size();

            // Level ke first aur last node ke indices
            unsigned long long stidx = q.front().second;
            unsigned long long endidx = q.back().second;

            // Width = last index - first index + 1
            unsigned long long currwidth = (endidx - stidx) + 1;

            // Maximum width update karo
            maxwidth = max(maxwidth, currwidth);

            for (int i = 0; i < currsize; i++) {

                auto curr = q.front();
                q.pop();

                // Left child ka index = 2*i + 1
                if (curr.first->left != NULL) {
                    q.push({
                        curr.first->left,
                        (2 * curr.second) + 1
                    });
                }

                // Right child ka index = 2*i + 2
                if (curr.first->right != NULL) {
                    q.push({
                        curr.first->right,
                        (2 * curr.second) + 2
                    });
                }
            }
        }

        return maxwidth;
    }
};