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
    TreeNode* rr(vector<int>& nums,int i,int j)
    {
        if(i>j)
        {
            return NULL;
        }
        int mid=(i+j)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=rr(nums,i,mid-1);
        root->right=rr(nums,mid+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       int i=0;
       int j=nums.size()-1;
       TreeNode* ans=rr(nums,i,j);
       return ans; 
    }
};