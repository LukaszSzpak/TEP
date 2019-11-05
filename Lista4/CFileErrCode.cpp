//
// Created by RC on 05.11.2019.
//

#include "CFileErrCode.h"
 CFileErrCode::CFileErrCode() {

}
 CFileErrCode::CFileErrCode(std::string sFileName) {
    this->vOpenFile(sFileName);
}
 CFileErrCode::~CFileErrCode() {
    delete(this->pf_file);
}

bool CFileErrCode::vOpenFile(std::string sFileName) {
    this->pf_file = fopen(sFileName.c_str(), "w+");

    if (this->pf_file == NULL)
        return false;

    return true;
}

bool CFileErrCode::vCloseFile(std::string sFileName) {
    if (this->pf_file != NULL) {
        fclose(this->pf_file);
        return true;
    }

    return false;
}

bool CFileErrCode::vPrintLine(std::string sText) {
    if (this->pf_file != NULL) {
        fprintf(this->pf_file, sText.c_str());
        return true;
    }

    return false;
}

bool CFileErrCode::vPrintManyLines(std::vector<std::string> sText) {
    for (int i = 0; i < sText.size(); i++) {
        bool isDone = this->vPrintLine(sText[i].c_str());

        if (!isDone)
            return false;
    }

    return true;
}
