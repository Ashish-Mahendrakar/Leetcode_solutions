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
    void revers(ListNode* &head,ListNode* &tail)
    {
        if(head==tail)
        {
            return;
        }
        ListNode* prev=NULL;
        ListNode* head2=head;
        ListNode* cur=head;
        ListNode* nxt=head->next;
        while(prev != tail)
        {
            cur->next=prev;
            prev=cur;
            cur=nxt;
            if(nxt != NULL)
                nxt=nxt->next;
        }
        head=prev;
        tail=head2;



    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int count=1;
        ListNode* temp=head;
        ListNode* lef=NULL;
        ListNode* lef_prev=NULL;
        ListNode* rig=NULL;
        ListNode* rig_nxt=NULL;
        ListNode* prev=NULL;
        //ListNode* nxt=temp->next;

        while(temp)
        {
            if(count==left)
            {
                lef=temp;
                lef_prev=prev;
            }

            if(count==right)
            {
                rig=temp;
                rig_nxt=temp->next;
            }
            prev=temp;
            temp=temp->next;
            
            count++;
        }

        revers(lef,rig);
        if(lef_prev==NULL)
        {
            head=lef;
        }
        else
        {
            lef_prev->next=lef;
        }
        
        rig->next=rig_nxt;
        return head;
    }
};