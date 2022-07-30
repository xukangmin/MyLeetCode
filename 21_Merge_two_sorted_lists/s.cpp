
// Definition for singly-linked list.

#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        auto prev_head = new ListNode(-1);

        auto prev = prev_head;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                prev->next = list1;
                list1 = list1->next;
            }
            else
            {
                prev->next = list2;
                list2 = list2->next;
            }

            prev = prev->next;
        }


        return prev_head->next;

    }
};


int main() {

    

    auto s = Solution();


    ListNode* a = new ListNode(1);

    a->next = new ListNode(2);

    a->next->next = new ListNode(10);


    ListNode* b = new ListNode(4);

    b->next = new ListNode(8);

    b->next->next = new ListNode(11);


    auto c = s.mergeTwoLists(a,b);

    while(c != nullptr)
    {
        cout << c->val << endl;

        c = c->next;
    }

}