// COUNT INVERSIONS  

#include <bits/stdc++.h> 
long long merge(long long arr[], int si, int ei){
    int mid=(si+ei)>>1;
    int i=si;
    int j=mid+1;
    long long cnt=0;
    vector<long long> v;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j])
        {
            v.push_back(arr[i]);
            i++;
        }
        else{
            v.push_back(arr[j]);
            j++;
            cnt+=mid-i+1;
        }
    }
    while(i<=mid){
        v.push_back(arr[i]);
        i++;
    }
    while(j<=ei){
        v.push_back(arr[j]);
        j++;
    }
    for(auto i: v){
        arr[si]=i;
        si++;
    }
    return cnt;
}

long long inversion_count(long long arr[], int si, int ei ){
    if(si>=ei)
        return 0;
    int mid=(si+ei)>>1;
    return inversion_count(arr, si, mid)+ inversion_count(arr,mid+1, ei)+ merge(arr, si, ei);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return inversion_count(arr, 0, n-1);
}

//10
//52244275 123047899 493394237 922363607 378906890 188674257 222477309 902683641 860884025 339100162
