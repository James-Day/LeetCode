package easy;

public class ConcatenationofArray {
    public int[] getConcatenation(int[] nums) {
      int[] answer = new int[nums.length *2];  
        int i =0;
        for(int number : nums){
       answer[i] = number;
        i++;
      }
        for(int number : nums){
       answer[i] = number;
        i++;
      }
        return answer;
    }
}