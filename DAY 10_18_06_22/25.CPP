//REVERSE A LINKED LIST
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if(head==NULL || head->next==NULL)
        //     return head;
        // ListNode* temp=head;
        // while(temp->next->next){
        //     temp=temp->next;
        // }
        // ListNode *x=temp->next;
        // temp->next=NULL;
        // x->next=reverseList(head);
        // return x;
        
        if(head==NULL || head->next==NULL)
            return head;
        ListNode * temp= reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
        
    }
}

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]