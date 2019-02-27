// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

string intToRoman(int num)
{
  string roman;

  std::vector<int> digitVec;
  int digit = num;

  while (digit != 0)
  {
    digitVec.emplace_back(digit % 10);
    digit = num / pow(10, digitVec.size());
  }

  for (int i = digitVec.size() - 1; i >= 0; --i)
  {
    digit = digitVec[i] * pow(10, i);

    while (digit > 0)
    {
      // 1000 - 3000
      if (i == 3)
      {
        roman += 'M';
        digit -= 1000;
      }
      // 100 - 900
      else if (i == 2)
      {
        if (digitVec[i] == 9)
        {
          roman += "CM";
          digit -= 900;
        }
        else if (5 <= digitVec[i] and digitVec[i] <= 8)
        {
          roman += 'D';
          digit -= 500;
          for (int j = 0; j < digitVec[i] - 5; ++j)
          {
            roman += 'C';
            digit -= 100;
          }
        }
        else if (digitVec[i] == 4)
        {
          roman += "CD";
          digit -= 400;
        }
        else
        {
          for (int j = 0; j < digitVec[i]; ++j)
          {
            roman += 'C';
            digit -= 100;
          }
        }

      }
      // 10 - 90
      else if (i == 1)
      {
        if (digitVec[i] == 9)
        {
          roman += "XC";
          digit -= 90;
        }
        else if (5 <= digitVec[i] and digitVec[i] <= 8)
        {
          roman += 'L';
          digit -= 50;
          for (int j = 0; j < digitVec[i] - 5; ++j)
          {
            roman += 'X';
            digit -= 10;
          }
        }
        else if (digitVec[i] == 4)
        {
          roman += "XL";
          digit -= 40;
        }
        else
        {
          for (int j = 0; j < digitVec[i]; ++j)
          {
            roman += 'X';
            digit -= 10;
          }
        }
      }
      // 0 - 9
      else
      {
        if (digitVec[i] == 9)
        {
          roman += "IX";
          digit -= 9;
        }
        else if (5 <= digitVec[i] and digitVec[i] <= 8)
        {
          roman += 'V';
          digit -= 5;
          for (int j = 0; j < digitVec[i] - 5; ++j)
          {
            roman += 'I';
            digit -= 1;
          }
        }
        else if (digitVec[i] == 4)
        {
          roman += "IV";
          digit -= 4;
        }
        else
        {
          for (int j = 0; j < digitVec[i]; ++j)
          {
            roman += 'I';
            digit -= 1;
          }
        }
      }
    }
  }

  return roman;
}
