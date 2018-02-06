import java.util.ArrayList;

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
    @Deprecated
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

    // my accepted solution
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

                // key code
                i++;
            }

            int limit = Math.min(left, s.length() - right - 1);
            palindrome = s.substring(left, right + 1);

            for (int j = 1; j <= limit; j++) {
                if (s.charAt(left - j) != s.charAt(right + j)) break;
                else palindrome = s.substring(left - j, right + j + 1);
            }

            //System.out.println("debug: " + child);
            ret = (palindrome.length() > ret.length()) ? palindrome : ret;
        }
        return ret;
    }


    /**
     * Official Suggested Solutions
     * Approach #1 (Longest Common Substring) [time limit exceeded]
     * <p>
     * based longest common substring
     */
    public String longestPalindromeCompare1(String s) {
        // reversed s
        String s2 = new StringBuilder(s).reverse().toString();

        if (s.length() == 0) return s;

        ArrayList<String> lcs = new ArrayList<>();
        int[][] arr = new int[s.length()][s2.length()];
        int max = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s.charAt(i) == s2.charAt(j)) {
                    if (i == 0 || j == 0) arr[i][j] = 1;
                    else arr[i][j] = arr[i - 1][j - 1] + 1;

                    if (max < arr[i][j]) {
                        int startidx = Math.min(i - arr[i][j] + 1, s.length() - j - 1);
                        int endidx = Math.max(i - arr[i][j] + 1, s.length() - j - 1);

                        // substring search
                        if (s2.indexOf(s.substring(startidx, endidx + 1)) != -1) {
                            max = arr[i][j];
                            lcs.clear();
                            lcs.add(s.substring(i - max + 1, i + 1));
                        }
                    } else if (max == arr[i][j]) {
                        int startidx = Math.min(i - max + 1, s.length() - j - 1);
                        int endidx = Math.max(i - max + 1, s.length() - j - 1);

                        if (s2.indexOf(s.substring(startidx, endidx + 1)) != -1) {
                            lcs.add(s.substring(i - max + 1, i + 1));
                        }
                    }
                }
            }
        }

        return lcs.get(0);
    }

    // Compare1 and Compare2 is the same actually
    // [time limit exceeded]
    public String longestPalindromeCompare2(String s) {
        // reversed s
        String s2 = new StringBuilder(s).reverse().toString();

        if (s.length() == 0) return s;

        ArrayList<String> lcs = new ArrayList<>();
        int[][] arr = new int[s.length()][s2.length()];
        int max = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s.charAt(i) == s2.charAt(j)) {
                    if (i == 0 || j == 0) arr[i][j] = 1;
                    else arr[i][j] = arr[i - 1][j - 1] + 1;

                    if (max < arr[i][j]) {
                        String test = s.substring(i - arr[i][j] + 1, i + 1);
                        if (isPalindromic(test)) {
                            max = test.length();
                            lcs.clear();
                            lcs.add(test);
                        }
                    } else if (max == arr[i][j]) {
                        String test = s.substring(i - max + 1, i + 1);
                        if (isPalindromic(test)) {
                            lcs.add(test);
                        }
                    }
                }
            }
        }
        return lcs.get(0);
    }

    public static boolean isPalindromic(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) return false;
        }
        return true;
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

        // official solution
        System.out.println("\nOffcial Solution 1: ");
        System.out.println(algo.longestPalindromeCompare1("caba"));
        System.out.println(algo.longestPalindromeCompare1("abacdfgdcaba"));

        System.out.println(algo.longestPalindromeCompare1("babad"));
        System.out.println(algo.longestPalindromeCompare1("cbbd"));
        System.out.println(algo.longestPalindromeCompare1("123913hellodavcouy"));
        System.out.println(algo.longestPalindromeCompare1(""));
        System.out.println(algo.longestPalindromeCompare1("1"));
        System.out.println(algo.longestPalindromeCompare1("ccc"));
        System.out.println(algo.longestPalindromeCompare1("11111"));
        System.out.println(algo.longestPalindromeCompare1("banana"));  // expected: anana

        System.out.println(algo.longestPalindromeCompare1("abacdf1221gdcaba"));

        System.out.println("\nOffcial Solution 2: ");
        System.out.println(isPalindromic("abcdefg"));
        System.out.println(isPalindromic("12321"));

        System.out.println(algo.longestPalindromeCompare2("caba"));
        System.out.println(algo.longestPalindromeCompare2("abacdfgdcaba"));

        System.out.println(algo.longestPalindromeCompare2("babad"));
        System.out.println(algo.longestPalindromeCompare2("cbbd"));
        System.out.println(algo.longestPalindromeCompare2("123913hellodavcouy"));
        System.out.println(algo.longestPalindromeCompare2(""));
        System.out.println(algo.longestPalindromeCompare2("1"));
        System.out.println(algo.longestPalindromeCompare2("ccc"));
        System.out.println(algo.longestPalindromeCompare2("11111"));
        System.out.println(algo.longestPalindromeCompare2("banana"));  // expected: anana

        System.out.println(algo.longestPalindromeCompare2("abacdf1221gdcaba"));
    }
}
