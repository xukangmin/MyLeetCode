/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/


#include <iostream>
#include <vector>

using namespace std;
/**
 * Definition for singly-linked list. */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode *ret = nullptr;
        ListNode **nn = &ret;
        int carry = 0;
        int sum;
        while(l1 != nullptr || l2 != nullptr) {

            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
            }
            if (l2 != nullptr) {
                sum += l2->val;
            }

            int cur_val = 0;
            if (sum >= 10) {
                cur_val += sum % 10;
                carry = 1;
            } else {
                cur_val += sum;
                carry = 0;
            }

            if (*nn == nullptr) {
                // no carry
                auto *node = new ListNode(cur_val);
                *nn = node;

            } else {
                // already created
                (*nn)->val += cur_val;
                if ((*nn)->val >= 10) {
                    (*nn)->val = (*nn)->val % 10;
                    carry = 1;
                }
            }

            nn = (&(*nn)->next);

            if (carry) {
                *nn = new ListNode(carry);
            }

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                l2 = l2->next;
            }
            
        }

        return ret;
    }
};

int main() {
    Solution sol;

    //vector<int> arr1 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    //vector<int> arr2 = {5,6,4};
    vector<int> arr1 = {1};
    vector<int> arr2 = {9,9};

    ListNode *d1 = new ListNode(arr1[0]);
    ListNode *d2 = new ListNode(arr2[0]);
    ListNode *n;

    n = d1;

    for(int i = 1; i < arr1.size(); i++) {
        n->next = new ListNode(arr1[i]);    
        n = n->next;
    }

    n = d2;

    for(int i = 1; i < arr2.size(); i++) {
        n->next = new ListNode(arr2[i]);    
        n = n->next;
    }
    ListNode* test = sol.addTwoNumbers(d1, d2);

    while(test != NULL) {
        cout << test->val << endl;
        test = test->next;
    }

    return 0;
}
