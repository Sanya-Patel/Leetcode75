/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (root == NULL) {
                return {};
            }
            queue<TreeNode*> q;
            q.push(root);
            q.push(NULL);
            vector<vector<int>> ans;
            vector<int> v;
            while (!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp == NULL) {
                    ans.push_back(v);
                    v.clear();
                    if (!q.empty()) {
                        q.push(NULL);
                    }
                } else {
                    if (temp->left) {
                        q.push(temp->left);
                    }
                    if (temp->right) {
                        q.push(temp->right);
                    }
                    v.push_back(temp->val);
                }
            }
            return ans;
        }
        vector<int> rightSideView(TreeNode* root) {
            vector<vector<int>> ans;
            ans = levelOrder(root);
            vector<int> res;
            for (int i = 0; i < ans.size(); i++) {
                int n = ans[i].size();
                res.push_back(ans[i][n - 1]);
            }
            return res;
        }
    };