class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n & 1) {
            return find(nums1, nums2, n / 2 + 1);
        } else {
            return (find(nums1, nums2, n / 2) + find(nums1, nums2, n / 2 + 1)) / 2;
        }
    }
    double find(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0, r = n1 - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            int res = detect(nums1[mid], nums2, k - mid - 1);
            if (res == 0) {
                return nums1[mid];
            } else if (res == -1) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        l = 0, r = n2 - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            int res = detect(nums2[mid], nums1, k - mid - 1);
            if (res == 0) {
                return nums2[mid];
            } else if (res == -1) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    int detect(int v, vector<int>& arr, int before) {
        if (before < 0) return 1; // too large
        if (before == 0) {
            if (arr.size() == 0 || arr[0] >= v) return 0; // ok
            return 1; // too large
        }
        if (arr.size() < before) return -1; // too small
        if (arr.size() == before) {
            if (arr[before - 1] <= v) return 0; // ok
            return -1; // too small
        }
        
        if (arr[before - 1] <= v && arr[before] >= v) return 0;
        if (arr[before - 1] > v) return -1;
        if (arr[before] < v) return 1;
    }
};
