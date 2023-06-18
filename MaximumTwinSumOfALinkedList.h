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
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *next = nullptr, *prev = nullptr;

        //find middle/end of list
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //reverse second half of list
        while(slow != nullptr) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        //find max sum of twins
        int max_sum = 0;
        while(prev) {
            max_sum = max(max_sum, (head->val + prev->val));
            head = head->next;
            prev = prev->next;
        }

        return max_sum;
    }
};
//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

/* other approach: saving values in a vector; needs more space, but keeps original list intact

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        while(head) {
            values.push_back(head->val);
            head = head->next;
        }

        int max_sum = 0, n = values.size();
        for(int i = 0; i < n/2; ++i) 
            max_sum = max(max_sum, values[i]+values[n-1-i]);

        return max_sum;
    }
};

*/