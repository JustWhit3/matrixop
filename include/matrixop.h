#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <iostream>

//MaxPtr template function declaration:
template <class A>
A MaxPtr (A *ptr, int a);

//Matrixop class declaration:
class matrixop
 {
  public:
   matrixop () {};
   matrixop (int);
   ~matrixop ();

   void inverse ();
   void reset ();
   void trace ();
   void determinant ();
   void linear_system ();
   void transpose ();
   void print_I (double **ptr);
   void print_data (double data);
   void print_sol (double *vet);
   void rank ();
   void matrix_norm ();
   double zero ();

   const matrixop& operator += (const matrixop &A);
   const matrixop& operator -= (const matrixop &A);
   const matrixop& operator *= (const matrixop &A);

   double t, d, rg, norm_1, norm_2, norm_3, zero_;
   double **k, **w, **I, **S, *mtr, *v, *V;
   int a;
 };
 
//Operator << redefinition declaration:
std::ostream& operator << (std::ostream& os, matrixop &A);
 
#endif
