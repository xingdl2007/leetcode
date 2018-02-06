/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * <p>
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * <p>
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * <p>
 * The median is 2.0
 * <p>
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * <p>
 * The median is (2 + 3)/2 = 2.5
 *
 * @author xingdl2007
 * @author xingdl2007@gmail.com
 */

public class MedianOfTwoSortedArrays {
    // naive solution: O(m+n)
    // WTF: accepted ?
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // merge sort
        int[] merge = new int[nums1.length + nums2.length];

        if (merge.length == 0) return 0.0;

        int i = 0, j = 0, k = 0;

        while (k <= merge.length / 2) {
            if (i < nums1.length && j < nums2.length) {
                if (nums1[i] < nums2[j]) merge[k++] = nums1[i++];
                else merge[k++] = nums2[j++];
            } else if (i == nums1.length)
                merge[k++] = nums2[j++];
            else
                merge[k++] = nums1[i++];
        }

        return (merge.length % 2 != 0) ? merge[merge.length / 2] :
                (merge[merge.length / 2 - 1] + merge[merge.length / 2]) * 1.0 / 2;
    }

    // official solution
    public double findMedianSortedArraysCompare(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        if (m > n) { // to ensure m<=n
            int[] temp = A;
            A = B;
            B = temp;
            int child = m;
            m = n;
            n = child;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j - 1] > A[i]) {
                iMin = iMin + 1; // i is too small
            } else if (i > iMin && A[i - 1] > B[j]) {
                iMax = iMax - 1; // i is too big
            } else { // i is perfect
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = B[j - 1];
                } else if (j == 0) {
                    maxLeft = A[i - 1];
                } else {
                    maxLeft = Math.max(A[i - 1], B[j - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m) {
                    minRight = B[j];
                } else if (j == n) {
                    minRight = A[i];
                } else {
                    minRight = Math.min(B[j], A[i]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }

    // according to leetcode article: https://leetcode.com/articles/median-of-two-sorted-arrays/
    public double findMedianSortedArraysExercise(int[] nums1, int[] nums2) {
        int i = 0, j;
        int m = nums1.length;
        int n = nums2.length;
        int imin = 0, imax = m;

        // swap nums1 and nums2 if m > n, make sure m < n according the article algorithm
        if (m > n) {
            return findMedianSortedArraysExercise(nums2, nums1);
        } else if (m == 0 && n == 0) {
            return 0.0;
        }

        // based on binary-search, O(min(m,n))
        while (imin <= imax) {
            i = (imin + imax) / 2;
            j = (m + n + 1) / 2 - i; // make sure left part is >= right part, which is (m+n+1) not (m+n)

            if (i < imax && nums2[j - 1] > nums1[i]) imin = i + 1;      // case 2: B[j-1] > A[i], increase i
            else if (i > imin && nums1[i - 1] > nums2[j]) imax = i - 1; // case 3: A[i-1] > B[j], decrease i
            else {
                // case 1: find perfect i, may dead loop if use specified `if condition` like case 1\2\3
                /*if ((i == m || j == 0 || nums2[j - 1] < nums1[i]) &&
                        (i == 0 || j == n || nums1[i - 1] < nums2[j])) {
                }*/

                // leftMax
                int leftMax;
                if (j == 0) leftMax = nums1[i - 1];
                else if (i == 0) leftMax = nums2[j - 1];
                else {
                    leftMax = Math.max(nums1[i - 1], nums2[j - 1]);
                }

                // return early, may no need to calculate rightMin
                if ((m + n) % 2 == 1) return leftMax;

                // rightMin
                int rightMin;
                if (j == n) rightMin = nums1[i];
                else if (i == m) rightMin = nums2[j];
                else {
                    rightMin = Math.min(nums1[i], nums2[j]);
                }
                return (leftMax + rightMin) / 2.0;
            }
        }

        return 0.0;
    }

    public static void main(String[] args) {
        MedianOfTwoSortedArrays algo = new MedianOfTwoSortedArrays();
        System.out.println(algo.findMedianSortedArrays(new int[]{1, 2}, new int[]{3, 4}));
        System.out.println(algo.findMedianSortedArrays(new int[]{1, 3}, new int[]{2}));
        System.out.println(algo.findMedianSortedArrays(new int[]{1, 3, 4, 5}, new int[]{8}));
        System.out.println(algo.findMedianSortedArrays(new int[]{1}, new int[]{3, 4, 5, 8}));

        System.out.println(algo.findMedianSortedArrays(new int[]{1}, new int[]{1}));

        // exception condition
        System.out.println(algo.findMedianSortedArrays(new int[]{}, new int[]{1}));
        System.out.println(algo.findMedianSortedArrays(new int[]{}, new int[]{}));


        // test exercise
        System.out.println("\nExercise: ");
        System.out.println(algo.findMedianSortedArraysExercise(new int[]{1, 2}, new int[]{3, 4}));
        System.out.println(algo.findMedianSortedArraysExercise(new int[]{1, 3}, new int[]{2}));
        System.out.println(algo.findMedianSortedArraysExercise(new int[]{1, 3, 4, 5}, new int[]{8}));
        System.out.println(algo.findMedianSortedArraysExercise(new int[]{1}, new int[]{3, 4, 5, 8}));

        // may dead loop
        System.out.println(algo.findMedianSortedArraysExercise(new int[]{1}, new int[]{1}));

        // exception condition
        System.out.println(algo.findMedianSortedArraysExercise(new int[]{}, new int[]{1}));
        System.out.println(algo.findMedianSortedArraysExercise(new int[]{}, new int[]{}));
    }
}
