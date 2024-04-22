#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1[], int nums1Size, int* nums2[], int nums2Size, int* returnSize) {
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    for (int i = 0; i < nums1Size; i++) {
        result[i] = -1;
    }
    for (int i = 0; i < nums1Size; i++) {
        int j = 0;
        while (nums2[j] != nums1[i]) {
            j++;
        }
        for (int k = j + 1; k < nums2Size; k++) {
            if (nums2[k] > nums1[i]) {
                result[i] = nums2[k];
                break;
            }
        }
    }
    
    return result;
}

int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    
    int returnSize;
    int* result = nextGreaterElement(nums1, nums1Size, nums2, nums2Size, &returnSize);
    
    printf("Next greater elements: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    
    free(result);
    
    return 0;
}
