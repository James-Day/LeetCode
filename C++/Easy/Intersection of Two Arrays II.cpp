class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> lookup;
        map<int,int> lookup2;
      for(int i =0; i < nums1.size(); i++){
        lookup[nums1[i]]++;
      }
      for(int j =0; j <nums2.size(); j++){
         lookup2[nums2[j]]++;
          }
    for(int k =0; k < nums2.size(); k++){
            while(lookup[nums2[k]] !=0 && lookup2[nums2[k]] !=0){
                ans.push_back(nums2[k]);
                lookup[nums2[k]]--;
                lookup2[nums2[k]]--;
            }
    }
        return ans;
    }
};