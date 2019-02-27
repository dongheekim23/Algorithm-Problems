// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

void GetStrings(const std::string& digits, std::vector<std::vector<char>>& stringSet)
{
  for (int i = 0; i < digits.size(); ++i)
  {
    if (digits[i] == '2')
      stringSet.emplace_back(std::vector<char>{'a', 'b', 'c'});
    else if (digits[i] == '3')
      stringSet.emplace_back(std::vector<char>{'d', 'e', 'f'});
    else if (digits[i] == '4')
      stringSet.emplace_back(std::vector<char>{'g', 'h', 'i'});
    else if (digits[i] == '5')
      stringSet.emplace_back(std::vector<char>{'j', 'k', 'l'});
    else if (digits[i] == '6')
      stringSet.emplace_back(std::vector<char>{'m', 'n', 'o'});
    else if (digits[i] == '7')
      stringSet.emplace_back(std::vector<char>{'p', 'q', 'r', 's'});
    else if (digits[i] == '8')
      stringSet.emplace_back(std::vector<char>{'t', 'u', 'v'});
    else if (digits[i] == '9')
      stringSet.emplace_back(std::vector<char>{'w', 'x', 'y', 'z'});
  }

}

void GetLetterCombinations(const std::vector<std::vector<char>>& stringSet, std::vector<std::string>& output,
  int index, int index2, std::string tempString)
{
  tempString += stringSet[index][index2];
  ++index;

  if (index <= stringSet.size() - 1)
  {
    for (int i = 0; i < stringSet[index].size(); ++i)
    {
      GetLetterCombinations(stringSet, output, index, i, tempString);
    }
  }
  else
  {
    output.emplace_back(tempString);
  }
}

std::vector<std::string> letterCombinations(std::string digits)
{
  if (digits.empty())
    return std::vector<std::string>{};

  std::vector<std::vector<char>> stringSet;

  GetStrings(digits, stringSet);

  std::vector<std::string> output;

  for (int i = 0; i < stringSet[0].size(); ++i)
    GetLetterCombinations(stringSet, output, 0, i, "");

  return output;
}
