//Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                v.push_back(mp[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            mp[nums[i]]=i;
        }
            return {-1,-1};
        }
};


// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].