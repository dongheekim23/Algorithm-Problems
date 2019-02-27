// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

vector<int> searchRange(vector<int>& nums, int target)
{
  if (nums.empty())
    return std::vector<int>{-1, -1};

  int left = 0;
  int right = nums.size() - 1;

  if (left == right && nums[0] == target)
  {
    return std::vector<int>{0, 0};
  }

  bool leftFound = false;
  bool rightFound = false;

  while (!(leftFound && rightFound) && left <= right)
  {
    if (nums[left] != target)
      ++left;
    else
      leftFound = true;

    if (nums[right] != target)
      --right;
    else
      rightFound = true;
  }

  if (leftFound && rightFound)
    return std::vector<int>{left, right};
  else
    return std::vector<int>{-1, -1};
}
