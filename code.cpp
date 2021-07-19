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
    vector<int>res;
    vector<vector<TreeNode *>>B;
    void uniquepath(TreeNode *root,TreeNode *target,vector<TreeNode*>A)
    {
        if(root!=NULL)
        {
            if(root==target)
            {
                A.push_back(root);
                B.push_back(A);
            }
            else
            {
                A.push_back(root);
                uniquepath(root->left,target,A);
                uniquepath(root->right,target,A);
            }
        }
    }
    void find(TreeNode* root,int k,int height)
    {
        if(root!=NULL  )
        {
            if(k==height)
            {
                res.push_back(root->val);
            }
            else
            {
                find(root->left,k,height+1);
                find(root->right,k,height+1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode *>A;
        uniquepath(root,target,A);
        find(B[0][B[0].size()-1],k,0);
        k--;
      for(int i=B[0].size()-2;i>=0;i--)
        {
           if(k>-1)
           {
               if(k==0)
               {
                   res.push_back(B[0][i]->val);
               }
               if(B[0][i]->left==B[0][i+1])
               {
                   find(B[0][i]->right,k,1);
               }
               else
               {
                   find(B[0][i]->left,k,1);
               }
               k--;
           }
           else
           {
               break;
           }
        }
   
        return res;
        
    }
};
