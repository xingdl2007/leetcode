/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * <p>
 * Example:
 * Input: "babad"
 * Output: "bab"
 * <p>
 * Note: "aba" is also a valid answer.
 * <p>
 * <p>
 * <p>
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 *
 * @author xingdl2007
 * @author xingdl2007@gmail.com
 */

public class LongestPalindromicSubstring {
    /**
     * helper function: return a palindromic string which start from specified index
     *
     * @param s original string
     * @param i index
     * @return palindromic string with i as its center (may be one of the center)
     */
    private String palindromeWithCenter(String s, int center) {
        String palindrome;

        int left = center, right = center;

        // find left edge
        while (left != 0 && s.charAt(left) == s.charAt(left - 1))
            left -= 1;

        // find right edge
        while (right != (s.length() - 1) && s.charAt(right) == s.charAt(right + 1))
            right += 1;

        int limit = Math.min(left, s.length() - right - 1);
        palindrome = s.substring(left, right + 1);

        for (int i = 1; i <= limit; i++) {
            if (s.charAt(left - i) != s.charAt(right + i)) break;
            else palindrome = s.substring(left - i, right + i + 1);
        }

        return palindrome;
    }

    public String longestPalindrome(String s) {
        // initial
        if (s.length() == 0) return s;
        String ret = s.substring(0, 1);

        for (int i = 1; i < s.length(); i++) {
            String palindrome;

            int left = i, right = i;

            // find left edge
            while (left != 0 && s.charAt(left) == s.charAt(left - 1))
                left -= 1;

            // find right edge
            while (right != (s.length() - 1) && s.charAt(right) == s.charAt(right + 1)) {
                right += 1;
                i++;
            }

            int limit = Math.min(left, s.length() - right - 1);
            palindrome = s.substring(left, right + 1);

            for (int j = 1; j <= limit; j++) {
                if (s.charAt(left - j) != s.charAt(right + j)) break;
                else palindrome = s.substring(left - j, right + j + 1);
            }

            //System.out.println("debug: " + tmp);
            ret = (palindrome.length() > ret.length()) ? palindrome : ret;
        }
        return ret;
    }

    public static void main(String[] args) {
        LongestPalindromicSubstring algo = new LongestPalindromicSubstring();

        // case 1: s.length() is odd, only one center
        System.out.println(algo.palindromeWithCenter("hellolleh", 4));
        System.out.println(algo.palindromeWithCenter("hellolleh", 1));


        // case 2: s.length() is even, two possible center
        System.out.println(algo.palindromeWithCenter("helloolleh", 4));
        System.out.println(algo.palindromeWithCenter("helloolleh", 5));

        // normal:
        System.out.println("\nNormal:");
        System.out.println(algo.longestPalindrome("babad"));
        System.out.println(algo.longestPalindrome("cbbd"));
        System.out.println(algo.longestPalindrome("123913hellodavcouy"));
        System.out.println(algo.longestPalindrome(""));
        System.out.println(algo.longestPalindrome("1"));
        System.out.println(algo.longestPalindrome("ccc"));
        System.out.println(algo.longestPalindrome("11111"));
        System.out.println(algo.longestPalindrome("banana"));  // expected: anana
    }
}
