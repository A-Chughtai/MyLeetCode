#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
        
    int *arr = new int [m + n];

    int i(0),j(0);
    bool a1_end(0),a2_end(0);

    int half_size = ((m + n) / 2) + 1;

    int x(0);
    for (; x < half_size; x++)
    {
        if(i == n)
        {
            a1_end = true;
            break;
        }
        if(j == m)
        {
            a2_end = true;
            break;
        }
        if(nums1[i] < nums2[j])
        {
            arr[x] = nums1[i];
            nums1[i];
            i++;
        }
        else
        {
            arr[x] = nums2[j];
            nums2[j];
            j++;
        }
    }

    if(a1_end)
    {
        for(; j < m && j < half_size; j++)
        {
            arr[x] = nums2[j];
            x++;
        }
    }
    else if(a2_end)
    {
        for(; i < n && i < half_size; i++)
        {
            arr[x] = nums1[i];
            x++;
        }
    }


    if((m + n) % 2 == 0)
    {
        return ((arr[(m + n) / 2] + arr[((m + n) / 2) - 1]) / 2.0);
    }
    else
    {
        return arr[(m + n) / 2];
    }
}