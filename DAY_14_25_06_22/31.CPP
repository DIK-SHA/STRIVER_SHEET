//Intersection of Two Linked Lists
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1=0,cnt2=0;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        
        while(tempA->next){
            cnt1++;
            tempA=tempA->next;
        }
        while(tempB->next){
            cnt2++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        while(cnt2<cnt1){
            tempA=tempA->next;
            cnt2++;
        }
        while(cnt1<cnt2){
            tempB=tempB->next;
            cnt1++;
        }
        while(tempA && tempB && tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};