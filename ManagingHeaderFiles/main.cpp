//
// Created by Liam Ross on 23/05/2023.
//

#include "my_math/Addition.h"
#include "my_math/Division.h"
#include "Print.h"

int main(){
    float first_no, second_no, result_add, result_div;

    std::cout<< "Enter first number\t";
    std::cin>> first_no;
    std::cout<< "Enter second number\t";
    std::cin>> second_no;

    result_add = addition(first_no , second_no);
    result_div = division(first_no , second_no);

    print("Addition", result_add);
    print("Division", result_div);

    return 0;
}
