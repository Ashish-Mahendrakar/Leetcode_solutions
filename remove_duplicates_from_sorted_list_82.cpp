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
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp)
        {
            ListNode* nxt=temp->next;
            if(nxt==NULL)
            {
                return head;
            }
            
            if(temp->val == nxt->val)
            {
                
                while(nxt->next && (nxt->next->val == temp->val))
                {
                    nxt=nxt->next;
                }
                
                if(prev==NULL)
                {
                    head=nxt->next;
                    prev=NULL;
                    temp=head;
                }
                else
                {
                    prev->next=nxt->next;
                
                    temp=nxt->next;
                }


            }
            else
            {
                prev=temp;
                temp=nxt;
                //cout<<prev->val<<" "<<temp->val<<endl;
            }
        }
        return head;
    }
};