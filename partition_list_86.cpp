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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* head1=new ListNode(-300);
        ListNode* head2=new ListNode(-300);

        ListNode* temp=head;
        unordered_map <ListNode*,bool> mp;
        while(temp)
        {
            if(temp->val < x)
            {
                mp[temp]=true;
            }
            else
            {
                mp[temp]=false;
            }
            temp=temp->next;
        }

        ListNode* temp1=head1;
        ListNode* temp2=head2;

        temp=head;
        while(temp)
        {
            if(mp[temp]==true)
            {
                temp1->next=new ListNode(temp->val);
                temp1=temp1->next;
            }
            else
            {
                temp2->next=new ListNode(temp->val);
                temp2=temp2->next; 
            }
            temp=temp->next;
        }
        temp1->next=head2->next;
        return head1->next;


    }
};