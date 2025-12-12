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
    int findlen(ListNode* &head)
    {
        ListNode* temp=head;
        int count=0;
        while(temp !=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    void reverse(ListNode* &head,ListNode* &tail)
    {
        //cout<<head->val<<" "<<tail->val<<endl;
        tail->next=NULL;
        ListNode* start=head;
        ListNode* end=tail;
        ListNode* prev=NULL;
        ListNode* curr=head;
        if(head==NULL || head->next==NULL)
        {
            return;
        }
        ListNode* nex=head->next;
        while(nex !=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=nex;
            nex=nex->next;
        }
        curr->next=prev;
        head=curr;
        tail=start;
    }
    ListNode* rr(ListNode* head,int &k,int len)
    {
        
        if(len <k)
        {
            return head;
        }
        len=len-k;
        int ref=k;
        ListNode* tail=head;
        while(ref !=1)
        {
            ref--;
            tail=tail->next;
        }
        //cout<<tail->val<<endl;
        ListNode* nextcon=tail->next;
        reverse(head,tail);
        tail->next=rr(nextcon,k,len);
        //cout<<head->val<<endl;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=findlen(head);
        ListNode* ans=rr(head,k,len);
        //cout<<ans->val;
        return ans ;
    }
};