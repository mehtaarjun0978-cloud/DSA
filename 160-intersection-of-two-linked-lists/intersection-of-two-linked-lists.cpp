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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // edge case
        if (headA == nullptr || headB == nullptr)
            return NULL;

        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        if(tempA->next == tempB)
            return tempB;
        
        if(tempB->next == tempA)
            return tempA;

        while (tempA != tempB) {
            tempA = tempA->next;
            tempB = tempB->next;

            if(tempA == tempB){
                return tempA;
            }

            if(tempA == nullptr )
                tempA = headB;
            
            if(tempB == nullptr)
                tempB = headA;        
        }
        //this will take care of both of null and first intersection point
        return tempA;
    }
};