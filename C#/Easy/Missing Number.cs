public class Solution
{
    public int MissingNumber(int[] nums)
    {
        HashSet<int> Set1 = new HashSet<int>();
        for (int i = 0; i < nums.Length; i++)
        {
            Set1.Add(nums[i]);
        }
        for (int i = 0; i <= nums.Length; i++)
        {
            if (!Set1.Contains(i))
            {
                return i;
            }
        }
        return -1;
    }
}