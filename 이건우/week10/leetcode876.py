class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        count = 1
        node = head
        while node.next:
            count += 1
            node = node.next
        mid = count // 2
        for _ in range(mid):
            head = head.next
        return head

