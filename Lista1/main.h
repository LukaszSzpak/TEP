//
// Created by RC on 15.10.2019.
//

#ifndef Lista1_main_h
#define Lista1_main_h

#include <iostream>
void v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int **(*piTable), int iSizeX, int iSizeY);
void print_tab(int **(*piTable), int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY);


#endif //Lista1_main_h