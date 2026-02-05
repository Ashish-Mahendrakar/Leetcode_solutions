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
    void rr(TreeNode* root,int &last,int &ans)
    {
        if(root==NULL)
        {
            return;
        }

        rr(root->left,last,ans);

        if(last !=-1)
        {
            int temp=root->val - last;
            if(temp<ans)
            {
                ans=temp;
            }
        }
        last=root->val;


        rr(root->right,last,ans);

    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        int last=-1;
        rr(root,last,ans);
        return  ans;
    }
};