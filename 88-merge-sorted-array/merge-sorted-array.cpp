class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int>temp;
        while(i<m){
            temp.push_back(nums1[i]);
            i++;
        }
        i=0;
        while(i<temp.size()&&j<n){
        if(temp[i]<nums2[j]){
            nums1[k]=temp[i];
            i++;
        }
        else{
            nums1[k]=nums2[j];
            j++;
        }
        k++;
        }
        while(i<temp.size()){
            nums1[k]=temp[i];
            i++;
            k++;
        }
        while(j<n){
            nums1[k]=nums2[j];
            j++;
            k++;
        }

    }
};