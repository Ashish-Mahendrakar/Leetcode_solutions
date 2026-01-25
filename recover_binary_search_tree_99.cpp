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
    void rr(TreeNode* root,long left_limit,long right_limit,long &f1,long &f2)
    {
        if(root==NULL)
        {
            return;
        }

        //left
        rr(root->left,left_limit,root->val,f1,f2);

        //fault
        if(root->val<left_limit || root->val>right_limit)
        {
            long d1;
            long d2;
            d1=root->val;
            if(root->val<left_limit)
            {
                d2=left_limit;
                swap(d1,d2);
            }
            else
            {
                d2=right_limit;
            }
            swap(d1,d2);
            //cout<<d1<<" "<<d2<<endl;
            if(f1 == LONG_MIN)
            {
                if(d1<d2)
                {
                    f1=d1;
                    f2=d2;
                }
                else
                {
                    f1=d2;
                    f2=d1;
                }
            }
            else
            {
                if(d1<f1)
                {
                    f1=d1;
                }
                else if(d2>f2)
                {
                    f2=d2;
                }
            }
            
            
            
        }
        //right
        rr(root->right,root->val,right_limit,f1,f2);
    }
    void inorder(TreeNode* root,long &f1,long & f2)
    {
        if(root==NULL)
        {
            return;
        }

        //left
        inorder(root->left,f1,f2);

        if(root->val == (int)f2)
        {
            root->val=(int)f1;
        }
        else if(root->val == (int)f1)
        {
            root->val=(int)f2;
        }
        //right
        inorder(root->right,f1,f2);
    }
    void recoverTree(TreeNode* root) {
        long f1=LONG_MIN;
        long f2=LONG_MIN;
        rr(root,LONG_MIN,LONG_MAX,f1,f2);
        //cout<<f1<<" "<<f2;
        inorder(root,f1,f2);

        

    }
};