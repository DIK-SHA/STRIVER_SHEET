//RAIN WATER TRAPPING
class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        vector<int> rightarr(n);
        vector<int> leftarr(n);
        rightarr[n-1]=height[n-1];
        leftarr[0]=height[0];
        for(int i=n-2;i>=0;i--){
            rightarr[i]=max(height[i],rightarr[i+1]);
        }
        for(int i=1;i<n;i++){
            leftarr[i]=max(leftarr[i-1],height[i]);
        }
        for(int i=1;i<n-1;i++){
            res=res+min(rightarr[i],leftarr[i])-height[i];
        }
        return res;
    }
};
// Input: height = [4,2,0,3,2,5]
// Output: 9
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation 
// map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 
// units of rain water (blue section) are being trapped.