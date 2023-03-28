#include<string>
#pragma once


class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::string doAlgorithm(std::string data) const = 0;
};