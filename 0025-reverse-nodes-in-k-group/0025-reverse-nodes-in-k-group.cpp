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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //TC = O(n), SC = O(1)
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize a dummy node to point to the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while (head != NULL) {
            // Check if there are at least k nodes left in the linked list
            ListNode* temp = head;
            for (int i = 0; i < k; ++i) {
                if (temp == NULL) {
                    return dummy->next; // Return if less than k nodes left
                }
                temp = temp->next;
            }

            // Reverse k nodes
            ListNode* prev = NULL;
            ListNode* curr = head;
            ListNode* next = NULL;
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect with the previous part
            prevGroupEnd->next = prev;
            head->next = curr;

            // Move the prevGroupEnd to the end of the reversed group
            prevGroupEnd = head;
            head = curr;
        }

        // Return the new head of the modified list
        ListNode* newHead = dummy->next;
        delete dummy; // Free the memory of dummy node
        return newHead;
    }
};


// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == NULL || head->next == NULL)  {
//             return head;
//         }

//         int cnt = 0;
//         ListNode* counter = head;
//         ListNode* temp = head;
//         ListNode* ans = head;

//         while(counter != NULL)  {   //count the number of nodes in LL
//             cnt++;
//             counter = counter->next;
//         }

//         cnt /= k;   //count the number of reversal groups that will be formed
//         stack<int> st;
//         int k1 = k;

//         while(temp != NULL) {
//             st.push(temp->val);
//             k1--;
//             temp = temp->next;

//             if(k1 == 0) {
//                 while(!st.empty())  {
//                     ans->val = st.top();
//                     st.pop();
//                     ans = ans->next;
//                 }
//                 cnt--;
//                 k1 = k;
//             }
//             if(cnt == 0)    {
//                 break;
//             }
//         }
//         return head;
//     }
// };