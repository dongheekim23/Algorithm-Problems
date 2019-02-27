// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

int strStr(string haystack, string needle)
{
  if (needle.empty())
    return 0;

  else if (haystack.empty() || haystack.length() < needle.length())
    return -1;

  int currIt = 0;
  int length = haystack.length();
  bool found = false;
  int correctCount = 0;

  while (currIt < length)
  {
    if (haystack[currIt] != needle[correctCount])
    {
      if (correctCount > 0)
      {
        currIt = currIt - correctCount;
        correctCount = 0;
      }
    }
    else
    {
      ++correctCount;

      if (correctCount == needle.length())
        return currIt - correctCount + 1;
    }

    ++currIt;
  }

  return -1;
}
