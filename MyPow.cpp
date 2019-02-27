// Implement pow(x, n), which calculates x raised to the power n(x^n).

double myPow(double x, int n)
{
  double result = 1;

  if (x == 0 || x == 1)
    return x;

  if (x == -1)
  {
    if (n % 2 == 0)
      return 1;
    else
      return -1;
  }

  if (n == 0)
    return 1;

  else if (n > 0)
  {
    for (int i = 0; i < n; ++i)
    {
      if (result == 0)
        return 0;

      result *= x;
    }
  }
  else
  {
    for (int i = n; i < 0; ++i)
    {
      if (result == 0)
        return 0;

      result /= x;
    }
  }

  return result;
}
