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

//actual addition
class Solution {
public:
    int length(ListNode* head)
    {
        ListNode* temp=head;
        int count=0;
        while(temp != NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }

    ListNode* reversell(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=length(l1);
        int len2=length(l2);
        //cout<<len1<<" "<<len2;
        ListNode* head1=l1;
        ListNode* head2=l2;
        if(len1 >= len2)
        {
            int carry=0;
            ListNode* temp1=head1;
            ListNode* temp2=head2;
            while(temp2 !=NULL)
            {
                temp1->val=temp1->val+temp2->val+carry;
                carry=temp1->val/10;
                temp1->val=temp1->val%10;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            while(carry !=0  && temp1!=NULL)
            {
                temp1->val=temp1->val+carry;
                carry=temp1->val/10;
                temp1->val=temp1->val%10;
                if(temp1->next==NULL && carry !=0)
                {
                    
                    ListNode* newnode=new ListNode(0);
                    //newnode->val=carry;
                    temp1->next=newnode;
                    // cout<<carry<<endl;
                    // newnode->val=carry;                    
                }
                temp1=temp1->next; 
                
            }
            if(carry !=0)
            {
                ListNode* temp=head1;
                while(temp->next != NULL)
                {
                    temp=temp->next;
                }
                ListNode* newnode=new ListNode(1);
                temp->next=newnode;
            }
            return head1;
        }
        else
        {
             int carry=0;
            ListNode* temp1=head2;
            ListNode* temp2=head1;
            while(temp2 !=NULL)
            {
                temp1->val=temp1->val+temp2->val+carry;
                carry=temp1->val/10;
                temp1->val=temp1->val%10;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            while(carry !=0  && temp1!=NULL)
            {
                temp1->val=temp1->val+carry;
                carry=temp1->val/10;
                temp1->val=temp1->val%10;
                if(temp1->next==NULL && carry !=0)
                {
                    
                    ListNode* newnode=new ListNode(0);
                    //newnode->val=carry;
                    temp1->next=newnode;
                    // cout<<carry<<endl;
                    // newnode->val=carry;                    
                }
                temp1=temp1->next; 
                
            }
            return head2;
        }
        
    }
};