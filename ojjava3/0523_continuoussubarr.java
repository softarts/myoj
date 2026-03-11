// prefix sum

import java.util.Map;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap();
        map.put(0, -1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            var r = sum % k;
            if (map.containsKey(r)) {
                int start = map.get(r);
                if (i - start > 1)
                    return true;
            } else {
                map.put(r, i);
            }
        }
        return false;
    }
}