// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
// Note: Do not modify the linked list.
//
// Follow up:
// Can you solve it without using extra space?

public class Solution142 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x, ListNode n) {
            val = x;
            next = n;
        }
    }

    public ListNode detectCycle(ListNode head) {
        ListNode p1 = head, p2 = head;
        while (p1 != null && p2 != null) {
            p1 = p1.next;
            p2 = p2.next;
            if (p1 != null) {
                p1 = p1.next;
            }
            if (p1 == p2) {
                break;
            }
        }
        // Does not have cycle
        if (p1 == null) {
            return null;
        }

        p2 = head;
        while (p1 != p2) {
           p1 = p1.next;
           p2 = p2.next;
        }
        return p1;
    }

    public static void main(String[] args) {
        Solution142 s = new Solution142();
        ListNode cycle = new ListNode(5, null);
        System.out.println(s.detectCycle(cycle));

        ListNode a = new ListNode(1, null);
        ListNode b = new ListNode(2, null);
        ListNode c = new ListNode(3, null);
        ListNode d = new ListNode(4, null);
        ListNode e = new ListNode(5, null);
        ListNode f = new ListNode(6, null);
        ListNode g = new ListNode(7, null);

        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        f.next = g;
        g.next = d;
        System.out.println(s.detectCycle(a).val);
        System.out.println(s.detectCycle(null));
    }
}
