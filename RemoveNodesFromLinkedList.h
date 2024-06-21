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
private:
    ListNode* reverseNodes(ListNode* head) {
        ListNode *previous = nullptr, *current = head;
        while(current != nullptr) {
            swap(current->next, previous);
            swap(current, previous);
        }
        return previous;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* previous = dummy;
        ListNode* current = reverseNodes(head); 

        while(current != nullptr) {
            if(current->val >= previous->val) {
                previous->next = current;
                previous = current;
            }
            
            current = current->next;
        }
        previous->next = nullptr;

        return reverseNodes(dummy->next);
    }
};

//https://leetcode.com/problems/remove-nodes-from-linked-list/

/* first approach using a vector to save the nodes and than check for greater values - all test cases passed; ran faster than the other approach, but needs more memory
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MAX, head);
        vector<ListNode*> nodes {dummy};
        while(head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }

        int max_to_right = -1;
        for(int i = nodes.size()-1; i > 0; --i) { 
            if(nodes[i]->val >= max_to_right) {
                max_to_right = nodes[i]->val;
                continue;
            }

            nodes[i-1]->next = nodes[i]->next;
        }

        return dummy->next;
    }
};
*/