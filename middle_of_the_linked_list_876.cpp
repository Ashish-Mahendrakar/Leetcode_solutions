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
        while(temp != NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
       int len=findlen(head);
       

        int count=len/2;
        ListNode* temp=head;
        while(count !=0)
        {
            temp=temp->next;
            count--;
        }
        
       
    
       return temp;
    }
};