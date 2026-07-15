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
    ListNode* reverse(ListNode* head){
        //edge case 
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* temp = head ;
        ListNode* front = nullptr ;
        ListNode* back = nullptr ;

        while(temp){
            front = temp->next;
            temp->next = back;
            back = temp ;
            temp = front;
        }

        return back ;        
    } 


    bool isPalindrome(ListNode* head) {
        //edge case 
        if(head == nullptr || head->next==nullptr)
            return true;
        
        ListNode* slow = head ;
        ListNode* fast = head ;


        while(fast->next && fast->next->next){
            slow = slow->next ;
            fast = fast->next->next;
        }

        //slow pointer is at middle
        ListNode* newhead = reverse(slow->next) ;

        //take two pointer one at starting one at end
        ListNode* first = head;
        ListNode* second = newhead;
        while(second != nullptr){
            if(first->val != second->val){
                reverse(newhead);
                return false;
            }

            //move both pointer to their next values 
            first = first->next ;
            second = second->next;
        }
        reverse(newhead);
        return true;
    }
};