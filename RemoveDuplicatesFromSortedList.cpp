// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

int removeDuplicates(vector<int>& nums)
{
  if (nums.empty())
    return 0;
  else if (nums.size() == 1)
    return 1;

  std::vector<int>::iterator currIt = nums.begin() + 1;
  std::vector<int>::iterator flagIt = nums.begin();

  int count = 1;

  while (currIt != nums.end())
  {
    if (*currIt != *flagIt)
    {
      *(++flagIt) = *currIt;
      ++count;
    }

    ++currIt;
  }

  return count;
}
