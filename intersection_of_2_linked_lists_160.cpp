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
    int findlen(ListNode *  &head)
    {
        int count=0;
        ListNode* temp=head;
        while(temp != NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    void rr(ListNode *headA, ListNode *headB,ListNode* &ans)
    {
        ListNode* tempa=headA;
        ListNode* tempb=headB;
        while(tempa!=NULL && tempb!=NULL && tempa != tempb)
        {
            tempa=tempa->next;
            tempb=tempb->next;
        }
        ans=tempa;
        return ;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=findlen(headA);
        int len2=findlen(headB);
        ListNode* ans=NULL;
        ListNode* theada=headA;
        ListNode* theadb=headB;
        //rr(headA,headB,ans);
        if(len1>len2)
        {
            int count=0;
            while(count < len1-len2)
            {
                theada=theada->next;
                count++;
            }
        }

        if(len2>len1)
        {
            int count=0;
            while(count < len2-len1)
            {
                theadb=theadb->next;
                count++;
            }
        }

        rr(theada,theadb,ans);
        //cout<<len1<<" "<<len2<<endl;
        return ans;
    }
};