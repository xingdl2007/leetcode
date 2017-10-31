import java.lang.reflect.Array;
import java.util.*;

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * <p>
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 * @author xingdl2007
 * @author xingdl2007=7@gmail.com
 */

public class TwoSum {
    // my accepted solution
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> companyMap = new HashMap<>();
        int[] result = new int[2];

        for (int i = 0; i < nums.length; i++) {
            if (companyMap.containsKey(nums[i])) {
                result[0] = companyMap.get(nums[i]);
                result[1] = i;
                break;
            } else {
                companyMap.put(target - nums[i], i);
            }
        }

        return result;
    }

    // official best solution
    public int[] twoSumCompare(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        int[] test = {2, 7, 11, 15};
        int[] result = new TwoSum().twoSum(test, 9);

        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(result[0]);
        list.add(result[1]);
        System.out.println(list);
    }
}
