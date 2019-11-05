//
// Created by RC on 05.11.2019.
//

#include "CFileLastError.h"

CFileLastError::CFileLastError() {

}

CFileLastError::CFileLastError(std::string sFileName) {
    this->vOpenFile(sFileName);
}

CFileLastError::~CFileLastError() {
    delete(this->pf_file);
}

void CFileLastError::vOpenFile(std::string sFileName) {
    this->b_last_error = false;

    this->pf_file = fopen(sFileName.c_str(), "w+");

    if (this->pf_file == NULL)
        this->b_last_error = true;
}

void CFileLastError::vCloseFile(std::string sFileName) {
    this->b_last_error = false;

    if (this->pf_file != NULL)
        fclose(this->pf_file);
    else
        this->b_last_error = true;

}

void CFileLastError::vPrintLine(std::string sText) {
    this->b_last_error = false;

    if (this->pf_file != NULL) {
        fprintf(this->pf_file, sText.c_str());
    } else
        this->b_last_error = true;
}

void CFileLastError::vPrintManyLines(std::vector<std::string> sText) {
    for (int i = 0; i < sText.size(); i++) {
        this->vPrintLine(sText[i].c_str());
    }
}
