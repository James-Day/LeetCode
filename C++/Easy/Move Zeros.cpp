// I noticed that my solution was not optimal, but was stuborn and decided to figure out if it was possible my way. 
// Proper solution is commented out below
class Solution {
public:
   void moveZeroes(vector<int>& nums) {
     for(int i =0; i < nums.size()-1; i++){
             if(nums[i] == 0){
                 int j =0;
                 for(j =i+1; j < nums.size() -1 && nums[j]==0; j++){
                     
                 } 
             swap(nums[i], nums[j]);
         }
     }
    }
    void swap (int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    /*void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    //move non zeros to front
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 	//fill end of array with zeros
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}*/
};