//POW(x,n)

 double myPow(double x, int n) {
    //this approach fails for 
    //0.00001
    //2147483647
        //MINE APPROACH ----------------------------------
        // if(n==1){
        //     return x;
        // }
        // long long nn=n;
        // if(n<0) nn=nn* -1;
        // return n>0?x*myPow(x, nn-1) : 1/x*myPow(x, nn-1);
        
        
        //TLE for the same test case---------------------------
        
        // long long nn=n;
        // if(n<0) nn=nn* -1;
        // double ans=1;
        // for(int i=1;i<=nn;i++){
        //     ans=ans*x;
        // }
        // if(n<0)
        //     return 1/ans;
        // return ans;
        
        //STRIVERS APPROACH -----------------------------------
        long long nn=n;
        if(n<0)
            nn=nn*-1;
        double ans=1;
        while(nn){
            if(nn%2==1){
                ans=ans*x;
                nn--;
            }
            else if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
        }
        return n<0 ? 1/ans : ans ;
}
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25

// Input: x = 2.10000, n = 3
// Output: 9.26100