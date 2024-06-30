#include <iostream>
#include "matrix.h"

int main() {
    Matrix A(3, 3);
    cout << "Matrix A(3, 3);" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    A.fill_row(2, 3, 1.0, 2.0, 3.0);
    A.fill_column(2, 2, 1.0, 2.0);
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << ++A << endl;" << endl;
    cout << ++A << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << A++ << endl;" << endl;
    cout << A++ << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << --A << endl;" << endl;
    cout << --A << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << A-- << endl;" << endl;
    cout << A-- << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << A * 5 << endl;" << endl;
    cout << A * 5 << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << 5 * A << endl;" << endl;
    cout << 5 * A << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "A *= 5;" << endl;
    A *= 5;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "Matrix B(A);" << endl;
    Matrix B(A);
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "B.transposed()" << endl;
    cout << B.transposed() << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "B.transpose();" << endl;
    B.transpose();
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "cout << A * B << endl;" << endl;
    cout << A * B << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "A *= B;" << endl;
    A *= B;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "cout << A + B << endl;" << endl;
    cout << A + B << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "A += B;" << endl;
    A += B;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "A - B;" << endl;
    cout << A - B << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "A -= B;" << endl;
    A -= B;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "cout << B << endl;" << endl;
    cout << B << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    A.add_row_to_row(2, 0);
    cout << "A.add_row_to_row(2, 1);" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    A.add_column_to_column(2, 0);
    cout << "A.add_column_to_column(2, 0);" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "A.add_column(-10);" << endl;
    A.add_column(-10);
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "A.add_row(-10);" << endl;
    A.add_row(-10);
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "A.delete_row(-10);" << endl;
    A.delete_row(-10);
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "A.delete_column(-10);" << endl;
    A.delete_column(-10);
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "A.swap_rows(0, 2);" << endl;
    A.swap_rows(0, 2);
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "A.swap_columns(0, 2);" << endl;
    A.swap_columns(0, 2);
    cout << "cout << A << endl;" << endl;
    cout << A << endl;
    cout << "------------------------------------" << endl;
    Matrix C(5, 5);
    C.fill_row(0, 5, 1.0, 2.0, 0.0, -1.0, 2.0);
    C.fill_row(1, 5, 2.0, -1.0, 1.0, 3.0, 5.0);
    C.fill_row(2, 5, 0.0, 1.0, 0.0, 2.0, -1.0);
    C.fill_row(3, 5, -1.0, 3.0, 2.0, 5.0, 0.0);
    C.fill_row(4, 5, 2.0, 5.0, -1.0, 0.0, 3.0);
    cout << "cout << C << endl;" << endl;
    cout << C << endl;
    cout << "cout << C.is_symmetrical() << endl;" << endl;
    cout << C.is_symmetrical() << endl;
    cout << "------------------------------------" << endl;
    Matrix D(3, 3);
    D.fill_row(0, 3, 0.0, 0.0, 2.0);
    D.fill_row(1, 3, 0.0, 0.0, -1.0);
    D.fill_row(2, 3, -2.0, 1.0, 0.0);
    cout << "cout << D << endl;" << endl;
    cout << D << endl;
    cout << "cout << D.is_anti_symmetrical() << endl;" << endl;
    cout << D.is_anti_symmetrical() << endl;
    return 0;
}
