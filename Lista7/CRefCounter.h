//
// Created by RC on 03.12.2019.
//

#ifndef LISTA7_CREFCOUNTER_H
#define LISTA7_CREFCOUNTER_H


class CRefCounter {
public:
    CRefCounter();
    int iAdd();
    int iDec() { return(--i_count); };
    int iGet() { return(i_count); }
    int iGetMax() { return max_count; };
private:
    int i_count;
    int max_count;
    void check_max();
};


#endif //LISTA7_CREFCOUNTER_H
