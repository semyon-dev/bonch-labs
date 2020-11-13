#pragma once

#include <string>

#include "COne.hpp"

class CTwo {
public:
    CTwo();

    CTwo(const double &d, const COne *p);

    CTwo(const CTwo &ctwo);

    virtual ~CTwo();

    CTwo &operator=(const CTwo &ctwo);

    const double &getDouble() const;

    const COne *getCOne() const;

    void print() const;

private:
    COne *p;
    double d;
};