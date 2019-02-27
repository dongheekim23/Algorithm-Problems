// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays.

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{      
    int totalSize = nums1.size() + nums2.size();
    int* mergedArray = new int[totalSize];

    std::vector<int>::iterator it1 = nums1.begin();
    std::vector<int>::iterator it2 = nums2.begin();

    for(int i = 0; i < totalSize; ++i)
    {
        if(it1 == nums1.end())
            mergedArray[i] = (*it2++);
        else if(it2 == nums2.end())
            mergedArray[i] = (*it1++);
        else
            *it1 < *it2 ? mergedArray[i] = (*it1++) : mergedArray[i] = (*it2++);


    }

    if(totalSize % 2 == 1)
    {
        return mergedArray[totalSize / 2];
    }
    else
    {
        return (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.f;
    }
}
