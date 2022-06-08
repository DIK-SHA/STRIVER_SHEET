//Merge nums1 and nums2 into a single array num1
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int k=m+n-1;
        int i=m-1;
        int j=n-1;
        while(i>=0 && j>=0){
            if(num1[i]>num2[j]){
                num1[k]=num1[i];
                k--;
                i--;
            }
            else{
                num1[k]=num2[j];
                k--,j--;
            }
        }
        while(j>=0){
            num1[k]=num2[j];
            k--,j--;
        }
    }

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.