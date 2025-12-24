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
    int hi(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int ans1=1+hi(root->left);
        int ans2=1+hi(root->right);

        return max(ans1,ans2);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;

        }
        int lef=hi(root->left);
        int ri=hi(root->right);
        if(abs(ri-lef)>1)
        {
            return false;
        }
        else
        {
            return isBalanced(root->left)&&isBalanced(root->right);
        }
    }
};