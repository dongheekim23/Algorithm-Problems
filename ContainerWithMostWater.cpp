static int Min(const int& a, const int& b)
{
  return a > b ? b : a;
}

static int GetArea(int width, int height)
{
  return width * height;
}

int maxArea(vector<int>& height)
{
  if (height.size() == 2)
    return Min(height[0], height[1]);

  int left = 0;
  int right = height.size() - 1;

  int currArea = 0;
  int maxArea = 0;

  while (left < right)
  {
    currArea = GetArea(right - left, Min(height[left], height[right]));

    if (currArea > maxArea)
      maxArea = currArea;

    if (height[left] < height[right])
    {
      ++left;
    }
    else
    {
      --right;
    }
  }

  return maxArea;
}
