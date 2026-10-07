class Solution {
public:
    int order = 0;

    int kthSmallest(TreeNode* root, int k) {
        // NULL node → element nahi mila
        if(root==NULL){
            return -1;
        }

        // Inorder: pehle left subtree
        if(root->left){
            int leftans = kthSmallest(root->left,k);
            // Left subtree mein answer mil gaya
            if(leftans!=-1){
                return leftans;
            }
        }

        // Current node kth smallest hai
        if(order + 1 == k){
            return root->val;
        }

        // Current node process ho gaya
        order++;

        // Inorder: ab right subtree
        if(root->right){
            int rightans = kthSmallest(root->right,k);
            // Right subtree mein answer mil gaya
            if(rightans!=-1){
                return rightans;
            }
        }

        // Abhi kth element nahi mila
        return -1;
    }
};


// Call             Action                         order
// ──────────────────────────────────────────────────────
// 2                left nahi
//                  order+1 == 3? ❌
//                  order++ → 1

// 3                left done
//                  order+1 == 3? ❌
//                  order++ → 2

// 4                left nahi
//                  order+1 == 3? ✅
//                  return 4

// ↑ 3              leftans = 4
//                  return 4

// ↑ 5              leftans = 4
//                  return 4

// Final Answer = 4


// Inorder traversal
//       ↓
// Har node par check: order + 1 == k ?
//       ↓
// Yes → current node = kth smallest
// No  → order++
//       ↓
// Right subtree