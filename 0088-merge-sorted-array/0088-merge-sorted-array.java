class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int first=m-1;
        int sec=n-1;
        int i=m+n-1;
        while(i>=0 && first>=0 && sec>=0){
            if(nums1[first]>nums2[sec])nums1[i]=nums1[first--];
            else nums1[i]=nums2[sec--];
            i--;
        }
        while(sec>=0)nums1[i--]=nums2[sec--];
    }
}