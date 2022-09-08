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
    /*
    step 1) find middle of list using Floyds Cycle Detection Algorithm
    step 2) reverse second next of second half of list to their formerly previous nodes
    step 3) check if palindrome
    */
    bool isPalindrome(ListNode* head) {
        //step 1
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //step 2
        ListNode *prev, *temp;
        prev = slow;
        slow = slow->next;
        prev->next = NULL;
        while(slow) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        //step 3
        //next of each list element after middle is reversed, fast=start of list, slow=end of list
        fast = head, slow = prev;
        while(slow != NULL && fast != NULL) {
            if(slow->val != fast->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        
        return true;
    }
};
//https://leetcode.com/problems/palindrome-linked-list/