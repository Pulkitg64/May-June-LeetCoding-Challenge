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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head== NULL || head->next == NULL || head->next->next==NULL)
            return head;
        
        ListNode *even = head->next;
        ListNode * odd = head;
        ListNode *result = odd;
        ListNode *head2 = even;
        
        while(odd->next!=NULL && even->next!=NULL)
        {
            if(odd->next!=NULL && odd->next->next !=NULL)
            {
                
                odd->next = odd->next->next;
                odd = odd->next;
            }
            else
            {
                odd->next=NULL;
            }
            
            if(even->next!=NULL && even->next->next !=NULL)
            {
                even->next = even->next->next;
                even = even->next;
            }
            else{
                even->next=NULL;
            }
            
            
        }
        
        odd->next= head2;
        return result;
        
            
        
    }
};