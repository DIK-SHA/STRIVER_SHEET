//Remove Duplicates from Sorted Array
// [1,1,2,3,4,5,5,5,5] 
// [1,1]
// [1,1,2]

class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
    //     if(nums.size()==0)
    //         return 0;
    //     int k=0,i;
    //     for(i=0;i<nums.size()-1;i++){
    //         while(i< nums.size()-1 &&  nums[i]==nums[i+1])
    //             i++;
    //         nums[k]=nums[i];
    //         k++;
    //     }
    //     if(i==nums.size()-1){
    //         nums[k]=nums[i];
    //         k++;
    //     }
    //     return k;
    // }
    
    //the above code is written by me and that one is a little bit efficient only 0.1%
    int removeDuplicates(vector<int>& nums){
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                count++;
            else 
                nums[i-count]=nums[i];
        }
        return nums.size()-count;
    }
};