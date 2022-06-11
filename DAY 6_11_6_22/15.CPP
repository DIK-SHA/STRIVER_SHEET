//Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //BRUTE FORCE------------------
        // sort(nums.begin(),nums.end());
        // if(nums.size()==1)
        //     return nums[0];
        // if(nums.size()==2)
        //     return nums[0];
        // for(int i=0;i<nums.size()-1;i++){
        //     int cnt=1;
        //     while(nums[i]==nums[i+1]){
        //         cnt++,i++;
        //     }
        //     if(cnt>nums.size()/2)
        //         return nums[i];
        // }
        // return -1;
        
        //BOYER MOORE'S VOTING ALGO-----------
        int cnt=0,ele=0;
        for(auto i:nums){
            if(cnt==0)
                ele=i;
            if(ele==i)
                cnt++;
            else
                cnt--;
        }
        return ele;
    }
};

// 7 7 5 7 5 1 5 7 5 5 7 7 5 5 5 5
//op: 5