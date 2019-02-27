// Given a 32-bit signed integer, reverse digits of an integer.

int reverse(int x) 
{        
    bool isNegative = false;
    if(x < 0)
    {
        if(x <= INT_MIN + 1)
            return 0;

        x *= -1;
        isNegative = true;
    }

    vector<int> storeVec;

    int digit = 0;
    int reversedNum = 0;
    bool zeroOccur = true;
    int nextNum = x / pow(10, digit);

    while(nextNum != 0)
    {
        nextNum %= 10;
        if(zeroOccur and nextNum != 0)
            zeroOccur = false;

        if(!zeroOccur || nextNum != 0)
            storeVec.emplace_back(nextNum);

        nextNum = x / pow(10, ++digit);
    }

    for(int i = storeVec.size() - 1; i >= 0; --i)
    {
        int adder = storeVec[i] * pow(10, storeVec.size() - 1 - i);

        if (adder < 0)
            return 0;

        if(!isNegative)
        {
            if(reversedNum <= INT_MAX - adder)
                reversedNum += adder;
            else
                return 0;
        }
        else
        {
            if(-reversedNum >= INT_MIN + adder)
                reversedNum += adder;
            else
                return 0;
        }

    }

    return isNegative == false ? reversedNum : -reversedNum;
}
