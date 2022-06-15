public class Solution
{
    public IList<string> FizzBuzz(int n)
    {
        const int FIZZ = 3;
        const int BUZZ = 5;

        List<string> ans = new List<string>();
        for (int i = 1; i <= n; i++)
        {
            string OneOutput = "";

            if (i % FIZZ == 0)
            {
                OneOutput += "Fizz";
            }
            if (i % BUZZ == 0)
            {
                OneOutput += "Buzz";
            }
            if (OneOutput == "")
            {
                OneOutput += i;
            }
            ans.Add(OneOutput);
        }
        return ans;
    }
}