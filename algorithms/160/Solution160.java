
// Write a program to find the node at which the intersection of two singly linked lists begins.
// For example, the following two linked lists:
//
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
// begin to intersect at node c1.
//
// Notes:
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

// Impressive
// Approach #3 (Two Pointers) [Accepted]
//
// Maintain two pointers pA and pB initialized at the head of A and B, respectively.
// Then let them both traverse through the lists, one node at a time.
//
// When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.);
// similarly when pB reaches the end of a list, redirect it the head of A.
// If at any point pA meets pB, then pA/pB is the intersection node.
//
// To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11}
// and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6),
// pB would reach the end of the merged list first, because pB traverses exactly 2 nodes less
// than pA does. By redirecting pB to head A, and pA to head B, we now ask pB to travel exactly
// 2 more nodes than pA would. So in the second iteration, they are guaranteed to reach the intersection
// node at the same time.
//
// If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches
// the end of a list, record the last element of A/B respectively. If the two last elements are not
// the same one, then the two lists have no intersections.
//
// Complexity Analysis
//
// Time complexity : O(m+n).
// Space complexity : O(1).

public class Solution160 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x, ListNode n) {
            val = x;
            next = n;
        }
    }

    // impressive !!!
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        ListNode a = headA;
        ListNode b = headB;
        while (a != b) {
            a = a == null ? headB : a.next;
            b = b == null ? headA : b.next;
        }
        return a;
    }

    // shame!!
    public ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        ListNode endA, endB, pA, pB;

        endA = null;
        endB = null;
        pA = headA;
        pB = headB;

        if (headA == null || headB == null) {
            return null;
        }

        while (endA == null || endB == null) {
            // intersection point
            if (pA == pB) {
                return pA;
            }

            if (pA.next == null) {
                endA = pA;
                pA = headB;
            } else {
                pA = pA.next;
            }

            if (pB.next == null) {
                endB = pB;
                pB = headA;
            } else {
                pB = pB.next;
            }

            if (endA != null && endB != null) {
                if (endA != endB) {
                    return null;
                } else {
                    endA = null;
                    endB = null;
                }
            }
        }

        return null;
    }

    public static void main(String[] args) {
        Solution160 s = new Solution160();
        ListNode common = new ListNode(9, new ListNode(11, null));

        ListNode headA = new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(7, common))));
        ListNode headB = new ListNode(2, new ListNode(4, common));

        ListNode in = s.getIntersectionNode(headA, headB);
        System.out.println(in.val);
    }
}