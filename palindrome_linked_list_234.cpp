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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* pre=head;
        ListNode* curr=head->next;
        if(curr->next==NULL)
        {
            curr->next=pre;
            pre->next=NULL;
            return curr;
        }
        ListNode* pos=curr->next;
        pre->next=NULL;
        while(curr != NULL)
        {
            curr->next=pre;
            pre=curr;
            curr=pos;
            if(curr != NULL)
              pos=curr->next;

        }
        return pre;
    }
    int findlen(ListNode* &head)
    {
        int count=0;
        ListNode* temp=head;
        while(temp !=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    bool isPalindrome(ListNode* head) {
        int len=findlen(head);
        //cout<<len;
        if(len ==1)
            return true;
        int count=len/2;
        ListNode* temp =head;
        while(count !=1)
        {
            
            temp=temp->next;
            count--;
        }
        //cout<<temp->val<<" "<<temp->next->val;

        ListNode* head2=NULL;
        if((len&1) == 0)
          {
            head2=temp->next;
            temp->next=NULL;
            }
        else{
            temp=temp->next;
            head2=temp->next;
            temp->next=NULL;

        }
        count =len/2;
        ListNode* temp1=reverse(head2);
        temp=head;

        while(count != 0)
        {
            count--;
            if(temp1->val != temp->val)
            {
                return false;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
        return true;
    }
};