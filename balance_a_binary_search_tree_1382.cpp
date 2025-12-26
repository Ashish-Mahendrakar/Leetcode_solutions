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
    void inod(TreeNode* root,vector <TreeNode*> &ino)
    {
        if(root==NULL)
        {
            return;
        }

        inod(root->left,ino);
        ino.push_back(root);
        inod(root->right,ino);
    }
    TreeNode* rr(vector <TreeNode*> &ino,int start,int end)
    {
        if(start>end)
        {
            //cout<<'j';
            return NULL;
        }
        else if(start == end)
        {
            //cout<<"h";
            return ino[start];
        }

        else{
        int mid=(start+end)/2;
        //cout<<mid<<" "<<start<<" "<<end<<" "<<ino.size()<<endl;
        ino[mid]->left=rr(ino,start,mid-1);
        ino[mid]->right=rr(ino,mid+1,end);

        return ino[mid];}
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector <TreeNode*> ino;
        inod(root,ino);
        TreeNode* ans=NULL;
        for(auto i : ino)
        {
            i->left=NULL;
            i->right=NULL;
        }
        int start=0;
        int end=ino.size()-1;
        ans=rr(ino,start,end);
        return ans;

    }
};