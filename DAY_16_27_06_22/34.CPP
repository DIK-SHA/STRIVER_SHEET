//Palindrome Linked List
class Solution {
public:
    ListNode*  findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode * head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* n;
        while(curr){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
    //Approach 1: puri linked list ko traverse kro aur ek array/vector m rakhlo fir uss         //vector ko check kro palindrom hai ya nhi.
    // TC - O(n)+O(n), one for keeping elements in vector, and one for checking vector is       //palindrom or not
        
    //Approach 2: check the linked list with its reverse 
    //Approach 3: 
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* mid=findMid(head);
        mid->next=reverse(mid->next);
        ListNode* temp=head;
        mid=mid->next;
        while(mid){
            if(mid->val !=temp->val)
                return false;
            mid=mid->next;
            temp=temp->next;
        }
        return true;
    }
};