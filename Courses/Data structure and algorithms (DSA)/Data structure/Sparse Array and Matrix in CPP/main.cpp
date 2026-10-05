#include <iostream>
#include "Node.h"
#include "ArrayList.h"
#include "SparseMatrix.h"


int main()
{
    /*
    ArrayList arry(10);

    arry.set_value(50,5);
    arry.set_value(20,2);
    arry.set_value(70,7);
    arry.set_value(40,4);

    ArrayList arry2(10);

    arry2.set_value(1,4);
    arry2.set_value(3,7);
    arry2.set_value(4,6);
  //  arry2.print_arry();
arry.add(arry2);
arry.print_arry();
*/
    SparseMatrix mat(10, 10);
    mat.set_value(5, 3, 5);
    mat.set_value(7, 3, 7);
    mat.set_value(2, 3, 2);
    mat.set_value(0, 3, 2);
    mat.set_value(6, 5, 6);
    mat.set_value(4, 5, 4);
    mat.set_value(3, 7, 3);
    mat.set_value(1, 7, 1);
    //mat.set_value(1, 70, 1);
    //mat.print_matrix();
   // mat.print_matrix_nonzero();
    SparseMatrix mat2(10, 10);
    mat2.set_value(5, 1, 9);
    mat2.set_value(6, 3, 8);
    mat2.set_value(9, 9, 9);

    mat.add(mat2);
    mat.print_matrix_nonzero();





    return 0;
}
