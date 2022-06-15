package easy;

public class RemoveDuplicatesFromSortedArray {
    public int removeDuplicates(int[] nums) {
        for(int i = 0; i <nums.length ;i++){
             for(int inc = i+1 ; inc < nums.length; inc++){
                 if(nums[i] == nums[inc]){
                     nums[inc] = -101;
                 }
             }
        }
        for(int num: nums){
       System.out.print(num + ",");
        }
        
        int pointerToUniqueNumber = 0;
         int inc = 0;
        
        while(inc != nums.length){
            if(nums[inc] == -101){
                inc++;
            }
        else if(nums[pointerToUniqueNumber] == -101){
            nums[pointerToUniqueNumber] = nums[inc];
            nums[inc] = -101;
             pointerToUniqueNumber++;
            inc++;
            
            }
            else{
                inc++;
                  pointerToUniqueNumber++;
                
            }
        }
        System.out.println();
         for(int num: nums){
       System.out.print(num + ",");
        }
    
        
        
        return pointerToUniqueNumber;
    }
}