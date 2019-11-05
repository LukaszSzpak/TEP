//
// Created by RC on 05.11.2019.
//

#ifndef LISTA4_CFILELASTERROR_H
#define LISTA4_CFILELASTERROR_H

#include <String>
#include <vector>


class CFileLastError {

private:
    bool b_last_error;
    FILE *pf_file;

public:
    bool bGetLastError() {return b_last_error;}
    CFileLastError();
    CFileLastError(std::string sFileName);
    ~CFileLastError();
    void vOpenFile(std::string sFileName);
    void vCloseFile(std::string sFileName);
    void vPrintLine(std::string sText);
    void vPrintManyLines(std::vector<std::string> sText);


};


#endif //LISTA4_CFILELASTERROR_H
