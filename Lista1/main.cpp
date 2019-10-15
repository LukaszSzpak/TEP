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

    int* array;
    array = v_alloc(5);
    showArray(array, 5);
    de_alloc(&array);

    std::cout<<"\nCzy sie udalo: "<<v_alloc2(&array, 5);
    showArray(array, 5);
    de_alloc(&array);

    return 0;
}