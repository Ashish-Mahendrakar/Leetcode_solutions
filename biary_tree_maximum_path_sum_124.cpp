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
    int rr(TreeNode* root,int &count)
    {
        if(root==NULL)
        {
            return 0;
        }

        // if(root->val < 0)
        // {
        //     return 0;
        // }
        //cout<<root->val<<endl;
        
        int left=rr(root->left,count);
        if(left<0)
        {
            left=0;
        }

        int right=rr(root->right,count);
         if(right<0)
        {
            right=0;
        }

        int sum=max(left,right)+root->val;

        if(sum>count)
        {
            count=sum;
        }

        sum=left+right+root->val;

        if(sum>count)
        {
            count=sum;
        }

        return max(left,right)+root->val;

    }
    void inorder(TreeNode* root,int &max,queue <TreeNode*> &q)
    {
        if(root == NULL)
        {
            return;
        }
        //left
        inorder(root->left,max,q);

        if(max < root->val)
        {
            max=root->val;
        }
        if(root->val < 0)
        {
            if(root->left)
            {
                if(root->left->val  >= 0)
                {
                    q.push(root->left);
                }
            }

            if(root->right)
            {
                if(root->right->val  >= 0)
                {
                    q.push(root->right);
                }
            }
        }

        //right
        inorder(root->right,max,q);

    }
    int maxPathSum(TreeNode* root) {
        int max=root->val;
        queue <TreeNode*> q;
        q.push(root);
        inorder(root,max,q);

        if(max<=0)
        {
            return max;
        }
        int ans=0;
        //cout<<q.size()<<endl;
        //while(!q.empty())
        //{
            TreeNode* t=q.front();
            q.pop();
            int count=0;
            int temp=rr(t,count);
            if(ans<count)
            {
                ans=count;
            }
        //}
        if(max>ans)
            return max;
        return ans;
    }
};