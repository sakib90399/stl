class Solution {
public:
    int mySqrt(int x) {
      
           if(x==0)return 0;// For special cases when x == 0 return 0.
        int lo=1,hi=x;// search range for the square root.
        int ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid==x/mid)return mid;
            else if(mid<x/mid){
                ans=mid;
                lo=mid+1;
            }else hi=mid-1;
        }
        return ans; 
    }
};