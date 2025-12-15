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
    int findlen(ListNode* &head,ListNode* &tail)
    {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            tail=temp;
            temp=temp->next;
            
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)
        {
            return head;
        }
        ListNode* tail=NULL;
        int len=findlen(head,tail);
        //cout<<len<<" "<<tail->val;
        int count=k%len;
        while(count !=0)
        {
            count--;
            ListNode* next_tail=head;
            while(next_tail->next != tail)
            {
                next_tail=next_tail->next;
            }
            next_tail->next=NULL;
            tail->next=head;
            head=tail;
            tail=next_tail;
        }
        return head;
    }
};