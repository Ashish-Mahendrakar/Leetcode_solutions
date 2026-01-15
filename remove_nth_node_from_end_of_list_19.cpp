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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        
        n=len-n+1;
        //cout<<n<<endl;
        if(n==1)
        {
            return head->next;
        }
        else if(n==len)
        {
            temp=head;
            ListNode* prev=head;
            while(temp->next)
            {
                len++;
                prev=temp;
                temp=temp->next;
            }
            prev->next=NULL;
            return head;
        }

        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nxt=curr->next;
        n--;
        while(n!=1)
        {
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
            n--;
        }
        //cout<<curr->val<<endl;
        prev->next=nxt;
        return head;
    }
};