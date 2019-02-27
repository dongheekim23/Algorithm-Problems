// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

void nextPermutation(vector<int>& nums)
{
  if (nums.empty() || nums.size() == 1)
    return;

  int left = 0;
  int right = nums.size() - 1;
  int curr = right - 1;
  int storePos = right;
  bool posFound = false;

  while (right > left && curr >= 0)
  {
    if (nums[curr] < nums[right])
    {
      if (nums[storePos] > nums[curr]
        && nums[storePos] < nums[right])
      {

      }
      else
        storePos = right;

      posFound = true;

      left = curr;
      --right;
      curr = right - 1;
    }
    else
    {
      --curr;

      if (curr <= left)
      {
        left = curr;
        --right;
        curr = right - 1;
      }
    }
  }

  if (posFound)
  {
    swap(nums[left], nums[storePos]);
    sort(nums.begin() + (left + 1), nums.end());
  }
  else
  {
    sort(nums.begin(), nums.end());
  }
}
