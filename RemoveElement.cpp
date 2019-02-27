// Given an array nums and a value val, remove all instances of that value in-place and return the new length.

int removeElement(vector<int>& nums, int val)
{
  if (nums.empty())
  {
    return 0;
  }

  int count = 0;

  int left = 0;
  int right = 0;
  int size = nums.size();

  while (right < size)
  {
    if (nums[right] != val)
    {
      nums[left] = nums[right];
      ++left;
      ++count;
    }

    ++right;
  }

  return count;
}
