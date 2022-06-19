//Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int maxi=0;
        int cnt=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] -1==nums[i])
            {
                cnt++;
                while(i<nums.size()-2 && nums[i+1]==nums[i+2]){
                    i++;
                }
            }
            else{
                maxi=max(maxi, cnt);
                cnt=1;
            }
        }
        maxi= max(maxi,cnt);                               
        return maxi;
    }
};

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Input: nums = [0,3,7,2,5,5,5,4,6,0,1]
// Output: 8