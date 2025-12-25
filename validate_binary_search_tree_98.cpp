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
    void inorder(TreeNode* root,TreeNode* &last,bool &status)
    {
        if(root == NULL)
        {
            return;
        }

        //left
        inorder(root->left,last,status);

        if(last !=NULL)
        {
            if(last->val >= root->val)
            {
                status=false;
            }
        }
        last=root;

        //right
        inorder(root->right,last,status);

    }
    bool isValidBST(TreeNode* root) {
        TreeNode* last=NULL;
        bool status=true;
        inorder(root,last,status);
        return status;
    }
};