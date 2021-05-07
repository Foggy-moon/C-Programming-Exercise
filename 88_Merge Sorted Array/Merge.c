void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //双指针
    int i = 0;
    int j = 0;
    int k = 0;
    int *numsTotal = (int *)malloc(sizeof(int)*(m + n));
    while (i < m && j <n) {
        if (nums1[i] <= nums2[j]) {
            numsTotal[k] = nums1[i];
            k++;
            i++;
        }
        else {
            numsTotal[k] = nums2[j];
            k++;
            j++;
        }
    }
    while (i<m) {
        numsTotal[k] = nums1[i];
        k++;
        i++;
    }
    while (j<n) {
        numsTotal[k] = nums2[j];
        k++;
        j++;
    }
    for (k = 0; k < m + n; k++) {
        nums1[k] = numsTotal[k];
    }
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //插入排序
    int i = 0;
    int j = 0;
    int k = 0;
    int tag = 0;
    for (i=0;i<n;i++){
        for(j=tag;j<m+i;j++){
            if(nums2[i]<=nums1[j]){
                tag = j;
                for(k=nums1Size-1;k>j;k--){
                    nums1[k] = nums1[k-1];
                }
                break;
            }
        }
        nums1[j] = nums2[i];
    }
}