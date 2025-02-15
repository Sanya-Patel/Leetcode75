/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root == NULL)
                return NULL;
            if (root->val == p->val || root->val == q->val)
                return root;
            TreeNode *Left, *Right;
            Left = lowestCommonAncestor(root->left, p, q);
            Right = lowestCommonAncestor(root->right, p, q);
            if (Left == NULL)
                return Right;
            if (Right == NULL)
                return Left;
            return root;
        }
    };