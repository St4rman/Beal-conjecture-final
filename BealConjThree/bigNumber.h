#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<int> Multiply(vector<int>& num1, int num2)
{
    vector<int> result;
    int carry = 0;

    for (int i = 0; i < num1.size() || carry; i++)
    {
        int product = carry + ((i < num1.size()) ? num1[i] * num2 : 0);
        result.push_back(product % 10);
        carry = product / 10;
    }

    return result;
}

vector<int> Power(int base, int exponent)
{
    if (exponent == 0)
        return vector<int>{1};

    vector<int> result;
    int temp = base;
    while (temp > 0)
    {
        result.push_back(temp % 10);
        temp /= 10;
    }
    for (int i = 2; i <= exponent; i++)
        result = Multiply(result, base);

    return result;
}

vector<int> Add(vector<int>& num1, vector<int>& num2)
{
    vector<int> result;
    int carry = 0;

    int i = 0, j = 0;
    while (i < num1.size() || j < num2.size() || carry)
    {
        int sum = carry;
        if (i < num1.size())
        {
            sum += num1[i];
            i++;
        }
        if (j < num2.size())
        {
            sum += num2[j];
            j++;
        }

        result.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}

int Compare(vector<int>& num1, vector<int>& num2)
{
    while (!num1.empty() && num1.back() == 0)
        num1.pop_back();
    while (!num2.empty() && num2.back() == 0)
        num2.pop_back();

    if (num1.size() < num2.size() || num1.size() > num2.size())
        return false;

    for (int i = num1.size() - 1; i >= 0; i--)
        if (num1[i] < num2[i] || num1[i] > num2[i])
            return false;

    return true;
}

void DisplayVector(vector<int>& vec)
{
    for (int i = vec.size() - 1; i >= 0; i--)
        cout << vec[i];
}