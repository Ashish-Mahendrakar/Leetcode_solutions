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
    void rr(TreeNode* p, TreeNode* q,bool &status)
    {
        if(p==NULL)
        {
            if(q!=NULL)
            {
                status= false;
            }
            return;
        }

        if(q==NULL)
        {
            if(p!=NULL)
            {
                status= false;
            }
            return;
        }

        if(p->val != q->val)
        {
            status=false;
        }

        //left
        rr(p->left,q->left,status);

        rr(p->right,q->right,status);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool status=true;
        rr(p,q,status);
        return status;
    }
};