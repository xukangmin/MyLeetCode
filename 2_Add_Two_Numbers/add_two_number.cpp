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
        ListNode *ret = NULL;


        int carry = 0;
        int sum;
        while(l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val;
            if (sum >= 10) {
                ret = new ListNode(sum % 10);
                carry = 1;
            } else {
                ret = new ListNode(sum);
                carry = 0;
            }
            if (carry) {
                ret->val += 1;
                carry = 0;
            }
            ret = new ListNode(0);
        }


    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    vector<int> arr2 = {5,6,4};

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

    return 0;
}
