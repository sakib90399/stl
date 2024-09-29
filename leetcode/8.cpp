class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0,hi=nums.size()-1,min_ele=nums[0];
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=nums[hi]){
                if(nums[mid]<min_ele)min_ele=nums[mid];
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return min_ele;
    }
};