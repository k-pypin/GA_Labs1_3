//
// Created by Trojan on 27.09.2017.
//

#include "Code.h"

int Code::L = 5;

std::ostream &operator<<(std::ostream &os, const Code &code) {
    int x = code.decNum;
    std::string s;

    while(x && s.size() < Code::L)
    {
        if(x % 2)
        {
            s.insert(s.begin(),'1');
        } else
        {
            s.insert(s.begin(),'0');
        }
        x = x / 2;
    }

    while(s.size() < Code::L)
    {
        s.insert(s.begin(),'0');
    }

    os << s;
    return os;
}

int Code::getPreference() const {
    return preference;
}

void Code::setPreference(int preference) {
    Code::preference = preference;
}

int Code::getDecNum() const {
    return decNum;
}

void Code::setDecNum(int decNum) {
    Code::decNum = decNum;
}

//!
//! \param lhs
//! \param rhs
//! \return haming distance
int Code::hammingDistance(Code &lhs, Code &rhs) {
    int x = lhs.decNum ^ rhs.decNum;
    int cnt = 0;
    int mask = 1;
    int i = 0;
    while(i < Code::L)
    {
        if(x & mask) cnt++;
        mask = mask << 1;
        i++;

    }
    return cnt;
}

bool Code::operator!=(const Code &rhs)const
{
    return this->decNum != rhs.decNum || this->preference != rhs.preference;
}

bool Code::operator<(const Code &rhs) const {
    return preference < rhs.preference;
}

std::vector<Code> Code::getOmega(std::vector<Code> &sSpace) {
    std::vector<Code> Omega;
    for (auto &i : sSpace) {
        if((Code::hammingDistance(*this, i) == 1) && (i != *this))
        {
            Omega.push_back(i);
        }
    }
    return Omega;
}

int Code::getLength() {
    return Code::L;
}

void Code::setLength(int len) {
    if(len > 0)
        Code::L = len;
}



