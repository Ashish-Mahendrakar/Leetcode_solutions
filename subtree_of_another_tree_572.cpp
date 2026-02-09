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
    void same(TreeNode* root, TreeNode* subRoot,bool &ans)
    {
        if(root==NULL && subRoot==NULL)
        {
            return;
        }
        else if(root==NULL)
        {
            ans=false;
            return;
        }
        else if(subRoot==NULL)
        {
            ans=false;
            return;
        }

        if(root->val != subRoot->val)
        {
            ans=false;
            return;
        }

        same(root->left,subRoot->left,ans);
        same(root->right,subRoot->right,ans);


    }
    void pre(TreeNode* root, TreeNode* subRoot,bool &ans)
    {
        if(root==NULL)
        {
            return;
        }
         
        if(ans==false)
        {
            if(root->val == subRoot->val)
            {
                ans=true;
                same(root,subRoot,ans);
            }
            pre(root->left,subRoot,ans);
            pre(root->right,subRoot,ans);
        }
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        pre(root,subRoot,ans);
        return ans;
    }
};