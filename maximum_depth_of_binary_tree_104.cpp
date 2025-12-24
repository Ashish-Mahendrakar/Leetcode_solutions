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
    int rr(TreeNode* root)
    {
        if(root ==NULL)
        {
            return 0;
        }

        //left
        int ans1=1+rr(root->left);

        //right
        int ans2=1+rr(root->right);
        return max(ans1,ans2);
    }
    int maxDepth(TreeNode* root) {
        return rr(root);
        
    }
};