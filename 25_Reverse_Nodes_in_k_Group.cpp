class Solution {
public:
    ListNode* reversell(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        struct ListNode* curr = head;
        struct ListNode* prev = NULL;
        struct ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode * next(ListNode * head,int k){
        k--;
        while(head!=NULL&&k>0){
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        struct ListNode *temp=head,*prev=NULL,*nextnode=NULL;
        while(temp!=NULL){
            struct ListNode * knode=next(temp,k);
            if(knode==NULL){
                if(prev!=NULL){
                    prev->next=temp;
                }
                break;
            }
            nextnode=knode->next;
            knode->next=NULL;
            reversell(temp);
            if(temp==head){
                head=knode;
            }else{
                prev->next=knode;
            }
            prev=temp;
            temp=nextnode;
        }
        return head;
    }
};