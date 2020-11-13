#pragma once

#include <string>

class COne {
public:
    COne();

    COne(float f, const char *ps);

    COne(const COne &cone);

    virtual ~COne();

    COne &operator=(const COne &r);

    float getF() const;

    char *getChar() const;

    void print() const;

private:
    float f;
    char *ps;
};