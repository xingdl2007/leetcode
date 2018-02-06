// Given a linked list, determine if it has a cycle in it.
//
// Follow up:
// Can you solve it without using extra space?
public class Solution141 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x, ListNode n) {
            val = x;
            next = n;
        }
    }

    public boolean hasCycle(ListNode head) {
        ListNode p1 = head, p2 = head;
        while (p1 != null && p2 != null) {
            p1 = p1.next;
            p2 = p2.next;
            if (p2 != null) {
                p2 = p2.next;
                if (p1 == p2) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean hasCycle2(ListNode head) {
        ListNode p1 = head, p2 = head;
        while (p1 != null && p1.next != null) {
            p1 = p1.next.next;
            p2 = p2.next;
            if (p1 == p2) {
                System.out.println(p1.val);
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution141 s = new Solution141();
        ListNode cycle = new ListNode(5, new ListNode(9, null));
        System.out.println(s.hasCycle(cycle));

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
        System.out.println(s.hasCycle2(a));

        System.out.println(s.hasCycle2(null));
    }
}
