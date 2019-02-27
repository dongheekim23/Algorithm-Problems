// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

void CheckPalindrome(std::string& output, int mid, const std::string& s, bool checkLeft)
{
  if (!(0 <= mid && mid < s.size()))
  {
    return;
  }

  int left = mid;
  int right = mid;

  std::string tempString;

  while (left >= 0 && right < s.size()
    && s[left] == s[right])
  {
    --left;
    ++right;
  }
  if (right != left)
  {
    tempString.assign(s.begin() + (left + 1), s.begin() + right);
  }

  std::string tempString2;
  left = mid;
  right = mid + 1;
  if (right < s.size())
  {
    while (left >= 0 && right < s.size()
      && s[left] == s[right])
    {
      --left;
      ++right;
    }
  }

  if (right - left > 1)
  {
    tempString2.assign(s.begin() + (left + 1), s.begin() + right);
  }


  if (tempString.size() > output.size()
    && tempString.size() > tempString2.size())
    output = tempString;

  else if (tempString2.size() > output.size()
    && tempString2.size() > tempString.size())
    output = tempString2;

  if(checkLeft)
    CheckPalindrome(output, mid - 1, s, checkLeft);
  else
    CheckPalindrome(output, mid + 1, s, checkLeft);
}

std::string longestPalindrome(std::string s)
{
  if (s.empty() || s.size() == 1)
    return s;

  int mid = s.size() / 2;
  std::string output;

  CheckPalindrome(output, mid - 1, s, true);
  CheckPalindrome(output, mid, s, false);

  return output;
}
