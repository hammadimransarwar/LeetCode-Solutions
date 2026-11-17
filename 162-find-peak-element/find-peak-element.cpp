class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int left=0,right=nums.size()-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(mid==0&&nums[mid+1]<nums[mid]) return 0;
            else if(mid==nums.size()-1&&nums[mid]>nums[mid-1]) return mid;
            else if(mid<nums.size()-1&&nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid+1]>nums[mid]){
                left=mid+1;
            }
            else right=mid;
        }
        return -1;
    }
};