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
    void rr(TreeNode* root, int &targetSum,long & sum,int & ans)
    {
        if(root==NULL)
        {
            return;
        }

        sum=sum+root->val;
        if(sum==targetSum)
        {
            ans++;
        }
        rr(root->left,targetSum,sum,ans);
        rr(root->right,targetSum,sum,ans);
        sum=sum-root->val;

    }
    void inorder(TreeNode* root, int &targetSum,long & sum,int & ans)
    {
        if(root==NULL)
        {
            return;
        }

        inorder(root->left,targetSum,sum,ans);

        rr(root,targetSum,sum,ans);

        inorder(root->right,targetSum,sum,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans=0;
        long sum=0;
        inorder(root,targetSum,sum,ans);
        return ans;
    }
};