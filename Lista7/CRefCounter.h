//
// Created by RC on 03.12.2019.
//

#ifndef LISTA7_CREFCOUNTER_H
#define LISTA7_CREFCOUNTER_H


class CRefCounter {
public:
    CRefCounter() { i_count; }
    int iAdd() { return(++i_count); }
    int iDec() { return(--i_count); };
    int iGet() { return(i_count); }
private:
    int i_count;
};


#endif //LISTA7_CREFCOUNTER_H
