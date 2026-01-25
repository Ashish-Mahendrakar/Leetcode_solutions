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
    void rr(TreeNode* root1,TreeNode* root2,bool &status)
    {
        if(root1 == NULL && root2==NULL)
        {
            return;
        }
        else if(root1 != NULL && root2==NULL)
        {
            status=false;
            return;
        }
        else if(root1 == NULL && root2!=NULL)
        {
            status=false;
            return;
        }

        if(root1->val == root2->val)
        {
            if(status)
            {
                rr(root1->left,root2->right,status);
                if(status)
                    rr(root1->right,root2->left,status);
            }
             
        }
        else
        {
            status=false;
            return;
        }
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* root1=root->left;
        TreeNode* root2=root->right;
        bool status=true;
        rr(root1,root2,status);
        return status;
    }
};