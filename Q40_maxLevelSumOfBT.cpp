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
    int fun(vector<int>v)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
        sum+=v[i];
        }
        return sum;
    }
        int maxLevelSum(TreeNode* root) {
             if(root==NULL)
            {
                return {};
            }
            queue<TreeNode*>q;
            vector<int>v;
            vector<int>v1;
            q.push(root);
            q.push(NULL);
             while(!q.empty())
             {
                 TreeNode*temp=q.front();
                 q.pop();
                 if(temp==NULL)
                 {
                    int x=fun(v);
                    v.clear();
                    v1.push_back(x);
                    
                    
                     if(!q.empty())
                       q.push(NULL);
                       
                       
                 }
                 else
                 {
                    v.push_back(temp->val);
                     if(temp->left)
                     {
                         q.push(temp->left);
                     }
                     if(temp->right)
                     {
                         q.push(temp->right);
                     }
                 }
    
    
             }
             int maxi=INT_MIN,idx=0;
             int x=1;
             for(int i=0;i<v1.size();i++)
             {
                //  maxi=max(maxi,v1[i]);
                 if(maxi<v1[i])
                 {
                     maxi=v1[i];
                     idx=i+1;
                 }
                  
             }
             return idx;
        }
    };