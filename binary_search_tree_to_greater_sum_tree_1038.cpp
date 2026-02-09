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
    void rin(TreeNode* root,int &sum)
    {
        if(root==NULL)
        {
            return;
        }

        rin(root->right,sum);
        //cout<<sum<<" "<<root->val<<endl;
        sum=sum+root->val;

        root->val=sum;

        rin(root->left,sum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        rin(root,sum);
        return root;
    }
};