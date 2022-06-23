//MERGE TWO LINKED LIST
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *c;
        if(list1==NULL)
        {
            return list2;
        }
        else if(list2==NULL)
            return list1;
        if(list1->val < list2->val){
            c=list1;
            c->next=mergeTwoLists(list1->next, list2);
            return c;
        }
        else {
            c=list2;
            c->next=mergeTwoLists(list1,list2->next);
            return c;
        }
        
    }
};