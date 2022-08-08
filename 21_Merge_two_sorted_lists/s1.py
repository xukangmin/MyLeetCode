# Definition for singly-linked list.
from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

        
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        pre_head = ListNode(-1)

        pre = pre_head

        while list1 and list2:
            
            # insert before list1 current node
            if list1.val <= list2.val:
                pre.next = list1
                list1 = list1.next
            else:
                pre.next = list2
                list2 = list2.next
            
            pre = pre.next

        pre.next = list1 if list1 is not None else list2
                
        return pre_head.next

a = ListNode(1)

a.next = ListNode(2)

a.next.next = ListNode(4)


b = ListNode(1)

b.next = ListNode(3)

b.next.next = ListNode(4)


s = Solution()

c = s.mergeTwoLists(a,b)

while c.next != None:
    print(c.val)
    c = c.next 