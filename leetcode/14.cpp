class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;

        while(s<e){
        int mid= s+(e-s)/2;
        if(arr[mid]-mid-1<k){
            s=mid+1;
        }
        else{
            e=mid;
        }
        }
        if(arr[s]-s-1<k){
            return s+k+1;
        }
        return s+k;
    }
};