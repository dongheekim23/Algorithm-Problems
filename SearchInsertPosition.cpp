// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.

void DivideSearch(const std::vector<int>& nums, int start, int end, int& index, const int& target, bool& found)
{
  if (found == true)
    return;

  if (start < end)
  {
    DivideSearch(nums, start, (end + start) / 2, index, target, found);
    DivideSearch(nums, (end + start) / 2 + 1, end, index, target, found);
  }
  else
  {
    if (nums[start] >= target)
    {
      index = start;
      found = true;
    }
  }
}

int searchInsert(vector<int>& nums, int target)
{
  bool found = false;
  int index = 0;
  DivideSearch(nums, 0, nums.size() - 1, index, target, found);

  return found == true ? index : nums.size();
}
