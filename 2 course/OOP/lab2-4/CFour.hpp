#pragma once

#include "CThree.hpp"

class CFour : public CThree {
public:
    CFour();

    CFour(const int i, const CThree &p);

    CFour(const CFour &cFour);

    ~CFour() override;

    int getInt() const;

    void setInt(int i);

    void print() const override;

private:
    int i;
};
