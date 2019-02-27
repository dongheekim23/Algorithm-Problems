// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

bool isPalindrome(int x)
{
  if (x < 0)
    return false;

  else if (0 < x && x < 10)
    return true;

  std::vector<int> digits;

  int powNum = 0;
  while (x / (int)pow(10, powNum) != 0)
  {
    digits.emplace_back((x / (int)pow(10, powNum)) % 10);
    ++powNum;
  }

  int center = digits.size() / 2;
  int it1 = center;
  int it2 = center;

  if (digits.size() % 2 == 0)
  {
    it2 = center;
    it1 = it2 - 1;
  }
  else
  {
    it2 = center + 1;
    it1 = center - 1;
  }

  for (int i = 0; i < center; ++i)
  {
    if (digits[it1] != digits[it2])
      return false;

    --it1;
    ++it2;
  }

  return true;
}
