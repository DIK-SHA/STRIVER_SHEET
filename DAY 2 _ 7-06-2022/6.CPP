//NEXT PERMUTATION OF AN ARRAY
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int brkpnt=-1;
        //find a breakpoint
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                brkpnt=i;
                break;
            }
        }
        // if no breakpoint
        if(brkpnt==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //if found a breakpoint 
        for(int i=n-1;i>brkpnt;i--){
            if(nums[i]>nums[brkpnt]){
                swap(nums[i],nums[brkpnt]);
                break;
            }
        }
        reverse(nums.begin()+brkpnt+1, nums.end());
    }
//ip - 
//[1 3 5 4 2]
//op -
//[1 4 2 3 5]