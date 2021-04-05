class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        for (int i = m-1; i >= 0; i--) {
            nums1[i+n] = nums1[i];
             
        }
        int j = 0, k = 0;
        while(j < m && k < n) {
            if (nums1[j+n] < nums2[k]) {
                nums1[j+k] = nums1[j+n];
                j++;
            } else {
                nums1[j+k] = nums2[k];
                k++;
            }
        }
        if (k < n) {
            for (int i = k; i < n; i ++) {
                nums1[i+m] = nums2[i];
            }
        }
        return;
    }
};

// 最后一步的时候判断+m 还是 +n

// 逆向双指针

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};
