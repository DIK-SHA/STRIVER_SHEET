//MAJORITY ELEMENT  >N/3
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int m1=-1 , m2=-1;
        int cnt1=0,cnt2=0;
        for(auto i : nums){
            if(i==m1)
                cnt1++;
            else if(i==m2)
                cnt2++;
            else if(cnt1==0)
                cnt1++,m1=i;
            else if(cnt2==0)
                cnt2++,m2=i;
            else
                cnt1--,cnt2--;
        }
        cnt1=cnt2=0;
        for(auto i:nums){
            if(i==m1){
                cnt1++;
            }
            else if(i==m2){
                cnt2++;
            }
        }
        if(cnt1>nums.size()/3)
            v.push_back(m1);
        if(cnt2>nums.size()/3)
            v.push_back(m2);
        return v;
    }
};


// Input: nums = [1]
// Output: [1]
// Input: nums = [3,2,3]
// Output: [3]
// Input: nums = [1,2]
// Output: [1,2]