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
    TreeNode* rr(vector<int>& preorder, vector<int>& inorder,int i,int j,unordered_map <int,int> &mp)
    {
        
        if(i>j)
        {
            //cout<<"h";
            return NULL;
        }
        if(i==j)
        {
            
            TreeNode* node=new TreeNode(inorder[i]);
            return node;
        }
        

        
        int pi=-1;
        int ii=-1;
        for(int k=0;k<preorder.size();k++)
        {
            if(mp[preorder[k]] >=i  && mp[preorder[k]] <=j)
            {
                pi=k;
                ii=mp[preorder[k]];
                break;
            }
        }
        //cout<<pi<<" "<<ii<<endl;

        TreeNode * root=new TreeNode(preorder[pi]);
        root->left=rr(preorder,inorder,i,ii-1,mp);
        root->right=rr(preorder,inorder,ii+1,j,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        int j=inorder.size()-1;
        unordered_map <int,int> mp;
        for(int k=i;k<=j;k++)
        {
            mp[inorder[k]]=k;
        }
        TreeNode* root=rr(preorder,inorder,i,j,mp);
        return root;
    }
};