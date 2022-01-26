<p align="center"><img src="https://github.com/JustWhit3/matrixop/blob/master/img/logo.svg" height=220></p>

<h3 align="center">My personal matrix algebra library</h3>
<p align="center">
    <img title="v2.0" alt="v2.0" src="https://img.shields.io/badge/version-v2.0-informational?style=flat-square"
    <a href="LICENSE">
        <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
    </a>
	<img title="C/C++11" alt="C/C++11" src="https://img.shields.io/badge/c++-11-informational?style=flat-square">
    </a>
</p>

***
## Table of contents
- [Introduction](#introduction)
- [Description of the repository](#description-of-the-repository)
- [Run the code](#run-the-code)
  * [Download](#download)
    * [Download the whole repository](#download-the-whole-repository)
    * [Download the latest release](#download-the-latest-release)
  * [Compile and run](#compile-and-run)
- [How does matrixop work](#how-does-matrixop-work)
  * [Include the library](#include-the-library)
  * [Class and functions](#class-and-functions)
- [List of features](#list-of-features)

## Introduction

The purpose of this library is to perform a good part of the main useful mathematical operations between matrices. It runs only over squared matrices of the same order. A list of the features is shown [here](#list-of-features).

If you want to cite this repository, please use [this](https://github.com/JustWhit3/matrixop/blob/master/CITATION.cff) template.

<img src="https://github.com/JustWhit3/matrixop/blob/master/img/matrixop.gif">

## Description of the repository

Repository diagram structure:
```
matrixop/
├── include/
│   ├── matrixop.h
├── src/
│   ├── matrixop.cpp
│   ├── main.cpp
│── img
│── README.md
│── CITATION.cff
│── License
│── .gitignore
├── makefile
```
Excluding this README.md file, the [*License*](https://github.com/JustWhit3/matrixop/blob/master/License) file and the [*.gitignore*](https://github.com/JustWhit3/matrixop/blob/master/.gitignore) file, the repository contains two directories:
- [**include**](https://github.com/JustWhit3/matrixop/tree/master/include): which contains the class and functions declaration file [*matrixop.h*](https://github.com/JustWhit3/matrixop/blob/master/include/matrixop.h).
- [**src**](https://github.com/JustWhit3/matrixop/tree/master/src): which contains two .cpp files:
  * [*matrixop.cpp*](https://github.com/JustWhit3/matrixop/blob/master/src/matrixop.cpp): which is the manipulator definition file.
  * [*main.cpp*](https://github.com/JustWhit3/matrixop/blob/master/src/main.cpp): which shows you an example of the manipulator utility.

There is also a [*makefile*](https://github.com/JustWhit3/matrixop/blob/master/makefile) for code compilation.

## Run the code

### Download

To download the manipulator you can proceed in two independent ways.

#### Download the whole repository

First of all, you need to download the code: go to the [main page](https://github.com/JustWhit3/matrixop) of the repository and click on the upper right green button called `Code`. Than click on `Download ZIP` and wait the download to be completed.

Then open a fresh shell and move the downloaded zipped file to your home directory (or to any other place you prefer):
```shell
mv Downloads/matrixop-master.zip $HOME
```
Where ``Downloads`` have to be replaced with the right name (and maybe the right path) of your downloads directory.

Now you have to enter your home folder (unless you were already in it, in this case skip this passage), extract the folder from the zipped file and renaming itself with its right repository name. Therefore lets type this commands one after the other:
```shell
cd $HOME
unzip matrixop-master.zip
mv matrixop-master matrixop
```
And that's all. You can enter the folder by simply typing:
```shell
cd matrixop
```

#### Download the latest release

Alternatively you can download the latest version of the repository from the ``Releases`` button on the right of the repository main page by clicking on the source code link. In this case the procedure is similar:

Open a fresh shell and move the downloaded zipped file to your home directory (or to any other place you prefer):
```shell
mv Downloads/matrixop-x.y.z.zip $HOME
```
Where `x.y.z` is the release tag and ``Downloads`` have to be replaced with the right name (and maybe the right path) of your downloads directory.

Now you have to enter your home folder (unless you were already in it, in this case skip this passage), extract the folder from the zipped file and renaming itself with its right repository name. Therefore lets type this commands one after the other:
```shell
cd $HOME
unzip matrixop-x.y.z.zip
mv matrixop-x.y.z matrixop
```

> If you prefer to download the tar.gz format of the release you have to run the `gunzip` command followed by the `tar -xvf` command on the zipped release folder and than proceed with `mv`. 

And that's all. You can enter the folder by simply typing:
```shell
cd matrixop
```

### Compile and run

Now, let's suppose to continue from the previous step. For the compilation part I prepared a [makefile](https://github.com/JustWhit3/matrixop/blob/master/makefile), in order to simplify this procedure. So you have to run the [makefile](https://github.com/JustWhit3/matrixop/blob/master/makefile) by typing:
```shell
make
```
An extra **obj** folder with object files and an executable called *main* are now created: you have simply to run this latter in order to run the entire example code:
```shell
./main
```
There is also an option to go back to the pre-compilation state of the code, to do this simply type this command:
```shell
make clean
```

## How does matrixop work

### Include the library

Once you have added the library to one of your project, you may want to be able to use it freely in your code. In order to let it works you have to include it at the beginning of a code in this way:
```c++
#include "path/to/matrixop/matrixop.h"
```
Where `path/to/matrixop/` is the path to the directory in which you put the matrixop library. If you put the library in the same folder of the project you are working with you have simply to do:
```c++
#include "matrixop.h"
```
In this latter case you can omit the full path. 
> Remember to do this also in [*matrixop.cpp*](https://github.com/JustWhit3/matrixop/blob/master/src/matrixop.cpp) 
> and in your makefile or maybe set this latter in order to avoid this path dependence.

Now you are able to access the class and al the functions of the library. 

### Class and functions

Functions:
- `template <class A> A MaxPtr (A *ptr, int a)`: template class useful to find maximum value of a pointer.

Class `matrixop`:
- Constructors: default `matrixop () {}` and `matrixop (int)`. 
- Destructor: `~Matrice ()`.
- Methods:
  * `inverse()`: method useful to invert the matrix with the Gauss algorithm.
  * `reset()`: method useful to reset a matrix.
  * `trace()`: gives the trace of a matrix.
  * `determinant()`: gives the determinant of a matrix.
  * `linear_system()`: gives solutions of a matrix linear system with the Gauss method.
  * `transpose()`: gives the transpose of a matrix.
  * `print_I(double **ptr)`: takes a matrix and prints it in a file.
  * `print_data(double data)`: takes a number and prints it in a file.
  * `print_sol(double *vet)`: takes a vector and prints it in a file.
  * `rank()`: gives the rank of a matrix.
  * `matrix_norm()`: gives the norm (norm-1, norm-inf, Frobenius norm) of a matrix.
  * `zero()`: method to set the "zero" of a matrix, in respect to the order of magnitude of each element.
- Operators redefinitions:
  * `+=`: for the sum between each element of matrices.
  * `-=`: for the difference between each element of matrices.
  * `*=`: for the rows by columns product of matrices.
  * `<<`: for the output print of a matrix.

## List of features

List of the documentations for each operation supported the by program:

- **Sum and difference between matrices**: see [here](https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:adding-and-subtracting-matrices/a/adding-and-subtracting-matrices).

- **Rows by columns matrices product**: see [here](https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:multiplying-matrices-by-matrices/a/multiplying-matrices).

- **Matrix inversion with Gaus algorithm**: see [here](https://www.intmath.com/matrices-determinants/inverse-matrix-gauss-jordan-elimination.php).

- **Matrix trace**: see [here](https://mathworld.wolfram.com/MatrixTrace.html).

- **Matrix determinant**: see [here](https://www.mathsisfun.com/algebra/matrix-determinant.html).

- **Resolution of linear systems by the Gauss method**: see [here](http://math.univ-lille1.fr/~tumpach/Site/Enseignement_files/TD2_Gauss_solution.pdf).

- **Matrix transpose**: see [here](https://chortle.ccsu.edu/VectorLessons/vmch13/vmch13_14.html).

- **Matrix rank**: see [here](https://stattrek.com/matrix-algebra/matrix-rank.aspx).

- **Matrix norm**: see [here](https://mathworld.wolfram.com/MatrixNorm.html).

- **Matrix Frobenius norm**: see [here](https://mathworld.wolfram.com/FrobeniusNorm.html).

