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
    int rr(TreeNode* root, TreeNode* &p, TreeNode* &q,TreeNode* &ans)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root==p)
        {
            int lef=rr(root->left,p,q,ans);
            int ri=rr(root->right,p,q,ans);
            if( ri==2)
            {
                ans=root;
            }
            if(lef==2 )
            {
                ans=root;
            }
            return 1;
        }
        if(root == q)
        {
            int lef=rr(root->left,p,q,ans);
            int ri=rr(root->right,p,q,ans);
            if(lef==1 )
            {
                ans=root;
            }
            if(lef==2 )
            {
                ans=root;
            }
            return 2;
        }

        int lef=rr(root->left,p,q,ans);
        int ri=rr(root->right,p,q,ans);
        if(lef==1 && ri==2)
        {
            ans=root;
        }
        if(lef==2 && ri==1)
        {
            ans=root;
        }
        return lef+ri;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=root;
        int temp=rr(root,p,q,ans);
        return ans;

    }
};