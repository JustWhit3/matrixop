# Reference guides folder

## General informations
This folder contains all the informations related to the classes and functions used for the program.

## Libraries ([link](https://github.com/JustWhit3/Matrix-Class/blob/master/Reference%20Guides/Libraries.c%2B%2B))
List of the libraries used in the program:
- `iostream`: for the standard input/output functions.
- `iomanip`: to manage spaces and distances between elements of each matrix in the output stream.
- `cstdlib`: this header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
- `fstream`: to manage input and output stream on files.
- `string`: to manage strings with no limit of lenght in bytes.
- `cmath`: to manage mathematical functions.
Is used the namespace `std` to simplify the writing of `iostream` functions.

## Template class: "MaxPtr" ([link](https://github.com/JustWhit3/Matrix-Class/blob/master/Reference%20Guides/templateClass_MaxPtr.c%2B%2B))
Template class useful to find maximum value of a pointer. It depends on the following arguments:
- `ptr` of general template type A*.
- `a` of integer type.

## Class: "Matrice" ([link](https://github.com/JustWhit3/Matrix-Class/blob/master/Reference%20Guides/Class_Matrice.c%2B%2B))
Class for the creation of matrix-type objects. It has only public methods, members and constructors.

### Constructors
- Constructors:  `Matrice () {}`, `Matrice (int)` to construct the matrix object.
- Destroyer: `~Matrice ()` to destroy the matrix object.

### Members
- Double type members: `t, d, rg, Norma_1, Norma_2, Norma_3, zero`.
- Double type member pointers: `**k, **w, **I, **S, *mtr, *v, *V`.
- Integer type members: `a`.

### Methods
- `Inversa()`: method useful to invert the matrix with the Gauss algorithm.
- `Azzera()`: method useful to reset a matrix.
- `Traccia()`: gives the trace of a matrix.
- `Determinante()`: gives the determinant of a matrix.
- `Sistema_Lineare()`: gives solutions of a matrix linear system with the Gauss method.
- `Trasposta()`: gives the transpose of a matrix.
- `Stampa_I(double **I)`: takes a matrix and prints it in a file.
- `Stampa_Dato(double dato)`: takes a number and prints it in a file.
- `Stampa_Sol(double *vet)`: takes a vector and prints it in a file.
- `Rango()`: gives the rank of a matrix.
- `Norma_Matriciale()`: gives the norm (norm-1, norm-inf- Frobenius norm) of a matrix.
- `Zero()`: method to set the "zero" of a matrix, in respect to the order of magnitude of each element.

### Operators redefinition
- `+=`: for the sum between each element of matrices.
- `-=`: for the difference between each element of matrices.
- `*=`: for the rows by columns product of matrices.
- `<<`: for the output print of a matrix.

## Function "Main" ([link](https://github.com/JustWhit3/Matrix-Class/blob/master/Reference%20Guides/Function_Main.c%2B%2B))
This function is an int-type function and is useful to run the code and methods of the "Matrice" class. It is nestled with if/else conditions and the use of "cerr" command for the error output stream.
