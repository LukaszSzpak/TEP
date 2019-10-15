#include <iostream>
#include "main.h"
#include "fun.h"



//testowy main
int main() {
    v_alloc_table_add_5(5);

    int** piTable;
    std::cout<<"Alokowanie: "<<b_alloc_table_2_dim(&piTable, 3, 5);
    print_tab(&piTable, 3, 5);
    std::cout<<"Usuwanie: "<<b_dealloc_table_2_dim(&piTable, 3, 5);

    return 0;
}