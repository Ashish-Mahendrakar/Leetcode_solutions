/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* rr(unordered_map <int,int> &mp,int i,int j)
    {
        if(i>j)
        {
            return NULL;
        }
        int mid=(i+j)/2;
        TreeNode* root=new TreeNode(mp[mid]);
        root->left=rr(mp,i,mid-1);
        root->right=rr(mp,mid+1,j);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }

        unordered_map <int,int> mp;
        ListNode* temp=head;
        int j=0;
        while(temp)
        {
            mp[j]=temp->val;
            temp=temp->next;
            j++;
        }
        TreeNode* ans=rr(mp,0,j-1);
        return ans;

    }
};