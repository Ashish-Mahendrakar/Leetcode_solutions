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
    char rr(TreeNode* root, TreeNode* &p, TreeNode* &q,TreeNode* &ans)
    {
        if(root==NULL)
        {
            return '!';
        }

        char ans1=rr(root->left,p,q,ans);
        char ans2=rr(root->right,p,q,ans);

        if(root==p)
        {
            
            if(ans1=='q' || ans2=='q')
            {
                if(ans==NULL)
                    ans=root;
            }
            return 'p';
        }

        if(root==q)
        {
            
            if(ans1=='p' || ans2=='p')
            {
                if(ans==NULL)
                    ans=root;
            }
            return 'q';
        }

        

        if(ans1=='p' && ans2=='q')
        {
            if(ans==NULL)
                ans=root;

            return '!';
        }
        else if(ans1=='q' && ans2=='p')
        {
            if(ans==NULL)
                ans=root;

            return '!';
        }
        else if((ans1=='q' && ans2!='p') || (ans1!='p' && ans2=='q') )
        {
            return 'q';
        }
        else if((ans1!='q' && ans2=='p') || (ans1=='p' && ans2!='q') )
        {
            return 'p';
        }
        else
        {
            return '!';
        }


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        char temp=rr(root,p,q,ans);
        return ans;
    }
};