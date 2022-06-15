public class Solution
{
    private int[] array;
    private int[] original;

    private Random rand = new Random();
    public Solution(int[] nums)
    {
        array = nums;
        original = new int[nums.Length];
        for (int i = 0; i < nums.Length; i++)
        {
            original[i] = nums[i];
        }
    }
    public int[] Reset()
    {
        array = original;
        original = new int[array.Length];
        for (int i = 0; i < array.Length; i++)
        {
            original[i] = array[i];
        }
        return array;
    }
    public int[] Shuffle()
    {
        List<int> cpy = new List<int>();
        for (int i = 0; i < array.Length; i++)
        {
            cpy.Add(array[i]);
        }


        for (int i = 0; i < array.Length; i++)
        {
            int RemoveIndex = rand.Next(cpy.Count);
            array[i] = cpy[RemoveIndex];
            cpy.RemoveAt(RemoveIndex);
        }
        return array;
    }
}