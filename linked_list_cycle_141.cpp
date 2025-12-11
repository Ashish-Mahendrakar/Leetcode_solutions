/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        {
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        if(fast->next==NULL)
        {
            return false;
        }
        fast=fast->next;
        slow=slow->next;
        while(fast !=NULL)
        {
            if(slow == fast)
            {
               return true;
            }
            else
            {
                slow =slow->next;
                fast=fast->next;

                if(fast != NULL)
                {
                    fast=fast->next;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }
};