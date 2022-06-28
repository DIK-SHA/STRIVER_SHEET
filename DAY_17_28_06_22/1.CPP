//Subset Sums 
// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(vector<int> arr, vector<int> op, vector<int>& res,int sum){
        if(arr.size()==0){
            res.push_back(sum);
            return;
        }
        vector<int> op1=op;
        vector<int> op2=op;
        op2.push_back(arr[0]);
        arr.erase(arr.begin()+0);
        solve(arr, op1, res,sum);
        solve(arr,op2, res, sum+op2.back());
        return;
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        vector<int> op;
        int sum=0;
        solve(arr, op,res, sum);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends