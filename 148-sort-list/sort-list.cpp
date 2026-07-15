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
    ListNode* sortList(ListNode* head) {

        // edge case
        if (head == nullptr || head->next == nullptr)
            return head;

        //splits into two part 
        ListNode* mid = findmid(head) ;
        ListNode* lefthead = head ;
        ListNode* righthead = mid->next ;
        mid->next = nullptr ; //break the connection between both parts 

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge(lefthead , righthead);
    }

private:
    ListNode* findmid(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head->next ;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0); // Dummy node simplifies edge cases
        ListNode* tail = &dummyHead;

        while(list1 && list2){
            if(list1->val < list2->val){
                // put list1 ahead of list two 
                tail->next = list1 ;
                list1= list1->next ;
            }
            else{
                tail->next = list2 ;
                list2 = list2->next;
            }

        tail = tail->next;

        }

        // Attach any remaining nodes
        if (list1 != nullptr) tail->next = list1;
        if (list2 != nullptr) tail->next = list2;
        
        return dummyHead.next;
    }
};