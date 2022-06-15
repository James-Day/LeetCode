    public class Solution
    {
        public int[] GetConcatenation(int[] nums)
        {
            int[] nums2 = new int[nums.Length * 2];
            for (int i = 0; i < nums.Length; i++)
            {
                nums2[i] = nums[i];
            }
            for (int i = 0; i < nums.Length; i++)
            {
                nums2[nums.Length + i] = nums[i];
            }
            return nums2;
        }
    };

