//
// Created by RC on 05.11.2019.
//

#ifndef LISTA4_CFILETHROWEX_H
#define LISTA4_CFILETHROWEX_H

#include <String>
#include <vector>

class CFileThrowEx {
public:
    CFileThrowEx();
    CFileThrowEx(std::string sFileName);
    ~CFileThrowEx();
    void vOpenFile(std::string sFileName);
    void vCloseFile(std::string sFileName);
    void vPrintLine(std::string sText);
    void vPrintManyLines(std::vector<std::string> sText);
private:
    FILE *pf_file;
};


#endif //LISTA4_CFILETHROWEX_H
