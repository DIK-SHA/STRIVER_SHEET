//
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
//   BRUTE FORCE--------->
//     int cnt=0;
//     for(int i=0;i<arr.size();i++){
//         int xr=0;
//         for(int j=i;j<arr.size();j++){
//             xr=xr^arr[j];
//             if(xr==x)
//             {
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
    
    int cnt=0,xr=0;
    map<int, int> mp;
    for(auto i: arr){
        xr=xr ^ i;
        if(xr==x)
            cnt++;
        if(mp.find(xr^x)!=mp.end())
            cnt+=mp[xr^x];
        mp[xr]++;
    }
    return cnt;
}

//4 2 2 6 4 x=6
// OP-> 4
// 5 3 8 3 10 x= 8
//OP-> 2
//EXPLAINATION: 
// In the first test case, the subarray from index 1 to index 3 i.e. {3,8,3} and 
// the subarray from index 2 to index 2 i.e. {8} have bitwise XOR equal to 8.