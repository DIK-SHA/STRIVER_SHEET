class Solution {
public:
    //this is kadanes algorithm
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN;// yaha pr sum ko zero se initiate mt krna
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum>sum){
                sum=currsum;
            }
            if(currsum<0)
                currsum=0;
        }
        return sum;
    }

};

// test cases
// -2 1 -3 4 -1 2 1-5 4
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.