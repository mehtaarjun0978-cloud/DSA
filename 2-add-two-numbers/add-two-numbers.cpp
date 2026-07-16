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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultHead  = new ListNode(-1) ;        //acting as a dummy 
        ListNode* result = resultHead;
        int carry = 0 ; //initial carry ==0 

        while((l1 != nullptr) || (l2 != nullptr) || carry != 0){
            // Get the values, defaulting to 0 if we've reached the end of a list
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry ;
            carry = sum/10 ;

            //make a new node and attach it to result - list
            result->next = new ListNode(sum%10);
            result = result->next ; 

            if(l1 != nullptr)  l1 = l1->next ;
            if(l2 != nullptr)  l2 = l2->next ;            
        }
        return resultHead->next ;
        
    }
};