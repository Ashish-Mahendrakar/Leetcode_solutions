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
    int rr(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        //left
        int ans1=rr(root->left);
        int ans2=rr(root->right);

        int ans3=hi(root->left)+hi(root->right);
        return max(ans1,max(ans2,ans3));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return rr(root);
    }
};