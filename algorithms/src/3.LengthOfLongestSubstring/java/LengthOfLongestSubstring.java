import java.io.IOException;
import java.io.StringReader;
import java.util.*;

/**
 * Given a string, find the length of the longest substring without repeating characters.
 * <p>
 * <p>
 * Examples:
 * <p>
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * <p>
 * Given "bbbbb", the answer is "b", with the length of 1.
 * <p>
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 * @author xingdl2007
 * @author xingdl2007@gmail.com
 */

public class LengthOfLongestSubstring {

    // my accepted solution: O(2n), O(min(m,n))
    public int lengthOfLongestSubstring(String s) {
        LinkedHashSet<Character> set = new LinkedHashSet<>();
        java.io.StringReader input = new java.io.StringReader(s);

        int max = 0;
        int c;

        try {
            while ((c = input.read()) != -1) {
                if (set.contains((char) c)) {
                    max = (set.size() > max) ? set.size() : max;

                    // Careful: very easy to write wrong code
                    // easy to invoke: set.clear(), which is totally wrong!
                    Iterator<Character> it = set.iterator();
                    while (it.hasNext()) {
                        Character old = it.next();
                        it.remove();
                        if (old.equals((char) c)) break;
                    }
                }
                set.add((char) c);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return (set.size() > max) ? set.size() : max;
    }


    // official solution: sliding window, actually the same thing, but better coding
    public int lengthOfLongestSubstringCompare(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))) {
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            } else {
                set.remove(s.charAt(i++));
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        LengthOfLongestSubstring s = new LengthOfLongestSubstring();

        System.out.println(s.lengthOfLongestSubstring("abcabcbb"));
        System.out.println(s.lengthOfLongestSubstring("bbbbb"));
        System.out.println(s.lengthOfLongestSubstring("pwwkew"));
<<<<<<<HEAD
        System.out.println(s.lengthOfLongestSubstring("cabcde"));
=======
>>>>>>>6 be3f004fe8f7538b1d1fc09aa15cd9ab4213c65
    }
}
