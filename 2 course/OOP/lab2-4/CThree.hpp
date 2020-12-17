#pragma once

#include "CTwo.hpp"

class CThree : public CTwo {
public:
    CThree();

    CThree(const int i, const CTwo &p);

    CThree(const CThree &cthree);

    ~CThree() override;

    int getInt() const;

    void setInt(int i);

    void print() const override;

private:
    int i;
};