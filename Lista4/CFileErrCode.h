//
// Created by RC on 05.11.2019.
//

#ifndef LISTA4_CFILEERRCODE_H
#define LISTA4_CFILEERRCODE_H

#include <string>
#include <vector>


class CFileErrCode {
    public:
        CFileErrCode();
        CFileErrCode(std::string sFileName);
        ~CFileErrCode();
        bool vOpenFile(std::string sFileName);
        bool vCloseFile(std::string sFileName);
        bool vPrintLine(std::string sText);
        bool vPrintManyLines(std::vector<std::string> sText);
    private:
        FILE *pf_file;
};


#endif //LISTA4_CFILEERRCODE_H
