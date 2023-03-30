import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Arrays.sort(nums);
        int start=0,end=0;
        while (nums[start] + nums[end] != target) {
            if ((nums[start] + nums[end]) > target) {
                end--;
            } else {
                start++;
            }
        }
        int[] temp = new int[2];
        temp[0]=start;
        temp[1]=end;
        return temp;
    }

    public static void main(String []args) {
        int[] nums=new int[]{2,7,11,15};
        int[] result = new Solution().twoSum(nums, 9);
        //return (result == new int[]{0,1}) ;
        Arrays.sort(result);
        System.out.println(Arrays.equals(result,new int[]{0,1}));
    }
}
