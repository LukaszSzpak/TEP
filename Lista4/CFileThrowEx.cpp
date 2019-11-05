//
// Created by RC on 05.11.2019.
//

#include "CFileThrowEx.h"

CFileThrowEx::CFileThrowEx() {

}

CFileThrowEx::CFileThrowEx(std::string sFileName) {
    this->vOpenFile(sFileName);
}

CFileThrowEx::~CFileThrowEx() {
    delete(this->pf_file);
}

void CFileThrowEx::vOpenFile(std::string sFileName) {
    this->pf_file = fopen(sFileName.c_str(), "w+");

    if (this->pf_file == NULL)
        throw "blad otwarcia pliku";
}

void CFileThrowEx::vCloseFile(std::string sFileName) {
    if (this->pf_file != NULL)
        fclose(this->pf_file);
    else
        throw "blad zamkniecia pliku";

}

void CFileThrowEx::vPrintLine(std::string sText) {

    if (this->pf_file != NULL) {
        fprintf(this->pf_file, sText.c_str());
    } else
        throw "Blad wpisania lini";
}

void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText) {
    for (int i = 0; i < sText.size(); i++) {
        this->vPrintLine(sText[i].c_str());
    }
}

