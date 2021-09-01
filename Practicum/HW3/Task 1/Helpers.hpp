#pragma once

template <typename T>
T getAbs(T num)
{
    return num >= 0 ? num : -num;
}

template <typename T>
T getMax(T num1, T num2)
{
    return num1 >= num2 ? num1 : num2;
}

template <typename T>
bool isBetweenOrEqual(T num, T min, T max)
{
    return num >= min && num <= max;
}