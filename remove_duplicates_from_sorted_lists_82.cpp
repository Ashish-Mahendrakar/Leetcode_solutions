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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head== NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* prev=head;
        ListNode* curr=head->next;
        if(curr->next== NULL)
        {
            if(prev->val == curr->val)
            {
                prev->next=NULL;
                return prev;
            }
            else
            {
                return prev;
            }
        }
        ListNode* nex=curr->next;
        while(nex != NULL)
        {
            if(prev->val == curr->val)
            {
                prev->next=nex;
                curr->next=NULL;
                curr=nex;
                nex=nex->next;
            }
            else
            {
                prev=curr;
                curr=nex;
                nex=nex->next;
            }
        }
        if(prev->val == curr->val)
        {
            prev->next=NULL;
        }
        return head;
        
        }
};