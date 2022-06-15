package easy;

public class PlusOne {
    public int[] plusOne(int[] digits) {
        boolean keepAdding = true;
        for(int i =0; keepAdding; i++){
        if(digits.length - (i+1) == -1){
           int[] arrayGrow = new int[digits.length+1];
            arrayGrow[0] =1;
            digits = arrayGrow;
            keepAdding = false;
        }
            else{
            digits[digits.length - (i+1)] +=1;
            keepAdding = false;
            if(digits[digits.length - (i+1)] == 10){
                digits[digits.length - (i+1)] = 0;
                keepAdding = true;
            }
            }
        }
        return digits;
    }
}