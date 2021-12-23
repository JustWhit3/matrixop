#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>

#include "../include/matrixop.h"

//MaxPtr template function declaration:
template <class A>
A MaxPtr (A *ptr, int a)
 {
  if (a==1) return *ptr;
  return *ptr > (a = MaxPtr (ptr+1, a-1)) ? *ptr : a;
 }

//Main constructor definition:
matrixop::matrixop (int)
 {
  std::cout << "Insert matrix order: " << std::endl;
  std::cin >> a;
   if (a<=0)
    {std::cerr << "Matrix order should be a positive integer!" << std::endl; exit(0);}

  mtr = new double [2*a];
  k = new double *[a];
  for (int i=0; i<a; i++) 
   k[i] = new double [a];
  I = new double *[a];
  for (int i=0; i<a; i++) 
   I[i] = new double [a];
  w = new double *[a];
  for (int i=0; i<a; i++) 
   w[i] = new double [2*a];
  S = new double *[a];
  for (int i=0; i<a; i++) 
   S[i] = new double [a];

    std::cout << "Insert matrix elements: " << std::endl;
    for (int i=0; i<a; i++)
     for (int j=0; j<a; j++)
      {std::cout << "Element of position (" << i+1 << "," << j+1 <<") ";
       std::cin >> k[i][j];}
       std::cout << std::endl;
    for (int i=0; i<a; i++)
    {for (int j=0; j<a; j++)			
      w[i][j] = k[i][j];} 
 }

//Destructor definition:
matrixop::~matrixop ()
 {
  for(int i=0;i<a;i++) {delete[] I[i], delete[] k[i];}
  for(int i=0;i<a;i++) delete[] w[i]; 
  for(int i=0;i<a;i++) delete[] S[i]; 
  delete[] I, k, w, mtr, v, V, S;
 }

//Inverse method definition:
void matrixop::inverse ()
 {
  //Put it near its identity matrix:
  for (int i=0; i<a; i++)
  {
   for (int j=0; j<(2*a); j++)
    if (j>=a)
    {if (j!=i+a)
      w[i][j]=0;
     else if (j==i+a)
      w[i][j]=1;}
  }

  //Check zeros in diagonal:
  for (int i=0; i<a; i++)
  {if (w[i][i]==0)
   {for (int j=0; j<a; j++)
    {if (w[j][i]!=0 && j!=i)
     {for (int m=0; m<(2*a); m++)
      {mtr[m] = w[j][m];
      w[j][m] = w[i][m];                 
      w[i][m] = mtr[m];}
     }
    }
   }
  }

  //Delete elements under diagonal:
  for (int j=0; j<a-1; j++)
   for (int i=j+1; i<a; i++)
   {double div = w[i][j]/w[j][j];
    if (w[j][j]==0)
     {break;}
    else
     {
      for (int m=0; m<(2*a); m++) mtr[m] = div*w[j][m];
      for (int m=0; m<(2*a); m++) w[i][m] -= mtr[m];}
   }

  //Check the determinant:
  d = 1;
  for (int i=0; i<a; i++)
   {d = d*w[i][i];}
    if (d<=zero() & d>=-zero()) 
     {std::cout << "Determinant is zero, matrix is not ivertible! " << std::endl; exit(0);} 
    else
     {std::cout << "Determinant is: " << d << " , matrix is invertible." << std::endl << std::endl;}

  //Delete elements over the diagonal:
  for (int j=a-1; j>0; j--)
  {for (int i=j-1; i>=0; i--)
   {double div = w[i][j]/w[j][j];
     for (int m=0; m<(2*a) ;m++) mtr[m] = div*w[j][m];
     for (int m=0; m<(2*a) ;m++) w[i][m] -= mtr[m];
   }
  }

  //Divide each row for the pivot:
  for (int i=0; i<a; i++) 
   if (w[i][i]!=1) 
   {double div = w[i][i];
    for (int m=0; m<(2*a); m++) 
     w[i][m] = w[i][m]/div;}

  //Print inverse matrix:
  {for (int i=0; i<a; i++) 
   {for (int m=0, j=a; j<(2*a); j++, m++)
    I[i][m] = w[i][j];}
  }
  std::cout << "Inverse matrix: " << std::endl;
  for (int i=0; i<a; i++)
   {for (int j=0; j<a; j++)
    {std::cout << std::setprecision (2) << std::setw (6) << I[i][j] << " ";}
     std::cout << std::endl;}
     std::cout << std::endl;
 }

//Reset method definition:
void matrixop::reset ()
 {
  mtr = new double [2*a];
  k = new double *[a];
  for (int i=0; i<a; i++) 
   k[i] = new double [a];
  I = new double *[a];
  for (int i=0; i<a; i++) 
   I[i] = new double [a];
  w = new double *[a];
  for (int i=0; i<a; i++) 
   w[i] = new double [2*a];
  S = new double *[a];
  for (int i=0; i<a; i++) 
   S[i] = new double [a];

    for (int i=0; i<a; i++)
     for (int j=0; j<a; j++)
      {k[i][j]=0;}
    for (int i=0; i<a; i++)
    {for (int j=0; j<a; j++)			
      w[i][j] = k[i][j];}
 }

//Trace method definition:
void matrixop::trace ()
 {
  t=0;
  for (int i=0; i<a; i++)
   t += w[i][i];
  std::cout << "Matrix trace is: " << t << std::endl;
 }

//Determinant method definition:
void matrixop::determinant ()
 {
  for (int j=0; j<a-1; j++)
   for (int i=j+1; i<a; i++)
    {
     double div = w[i][j]/w[j][j];
     for (int m=0; m<(2*a); m++) mtr[m] = div*w[j][m];
      for (int m=0; m<(2*a); m++) w[i][m] -= mtr[m];
    }

  d = 1;
  for (int i=0; i<a; i++)
   d = d*w[i][i];
    {std::cout << "Determinant is: " << d << std::endl;}
 }

//Linear_system method definition:
void matrixop::linear_system ()
 {
  inverse ();
  std::cout << "Sistem solution is unique, therefore I can insert vector B coordinates:" << std::endl << std::endl;
  v = new double [a];
  V = new double [a];
  std::cout << "Insert elements of vector of dimension " << a << ": " << std::endl;
   for (int i=0; i<a; i++)
    {std::cout << "Element of position " << i+1 << ": ";
       std::cin >> v[i];}
       std::cout << std::endl;
  std::cout << "Vector B: " << std::endl;
    for (int i=0; i<a; i++)
      {std::cout << std::setprecision (2) << std::setw (6) << v[i] << " " << std::endl;}
       std::cout << std::endl;
  std::cout << "Linear sistem solutions are:" << std::endl;
   for (int i=0; i<a; i++)
    V[i]=0;
   for (int i=0; i<a; i++)
    for (int j=0; j<a ;j++)
     V[i]+=I[i][j]*v[j];
   for (int i=0; i<a; i++)
      {std::cout << std::setprecision (2) << std::setw (6) <<"x[" <<i+1 <<"] = " << V[i] << " " << std::endl;}
       std::cout << std::endl;
 }

//Transpose method definition:
void matrixop::transpose ()
 {
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)	
     w[j][i] = k[i][j];
   }
  std::cout << "Transpose matrix: " << std::endl;
    for (int i=0; i<a; i++)
     {for (int j=0; j<a; j++)
      {std::cout << std::setprecision (2) << std::setw (6) << w[i][j] << " ";}
       std::cout << std::endl;}
    std::cout << std::endl;
 }

//Operator += redefinition:
const matrixop &matrixop::operator += (const matrixop &A)
 {
  for (int i=0; i<(A.a); i++)
   for (int j=0; j<(A.a); j++)
    k[i][j] += A.k[i][j];
  return *this;
 }

//Operator -= redefinition:
const matrixop &matrixop::operator -= (const matrixop &A)
 {
  for (int i=0; i<(A.a); i++)
   for (int j=0; j<(A.a); j++)
    k[i][j] -= A.k[i][j];
  return *this;
 }

//Operator *= redefinition:
const matrixop &matrixop::operator *= (const matrixop &A)
 {
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     I[i][j]=0;
   }

  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     for(int h=0; h<a ;h++)
      I[i][j]+=k[i][h]*A.k[h][j];
   }
  std::cout << "Row by column matrices product: " << std::endl;
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     {std::cout << std::setprecision (2) << std::setw (6) << I[i][j] << " ";}
      std::cout << std::endl;}
    std::cout << std::endl;
  return *this;
 }

//Operator << redefinition:
std::ostream& operator << (std::ostream& os, matrixop &A)
 {
  std::cout << "Matrix is: " << std::endl;
    for (int i=0; i<A.a; i++)
     {for (int j=0; j<A.a; j++)
      {os << std::setprecision (2) << std::setw (6) << A.k[i][j] << " ";}
       os << std::endl;}
    os << std::endl;
  return os;
 }

//Print_I method definition:
void matrixop::print_I (double **I)
 {
  std::string Nome_File;
  std::cout << "In which file do you want to save the data (please write it all up, if file doesn't exist it will be created)?" << std::endl;
  std::cin >> Nome_File;
  std::fstream stream;
  stream.open (Nome_File, std::ios::out|std::ios::app);
  if (!stream)
   {std::cerr << "Cannot open the file." << std::endl; exit (0);}
   stream << "La matrice salvata è:" << std::endl << std::endl;
    for (int i=0; i<a; i++)
     {for (int j=0; j<a; j++)
      {stream << std::setprecision (2) << std::setw (6) << I[i][j] << " ";}
       stream << std::endl;}
    stream << std::endl;
  std::cout << "File now has: " << stream.seekg (0, std::ios::end).tellg() << " bytes." << std::endl << std::endl;
  stream.close ();
 }

//Print_data method definition:
void matrixop::print_data (double data)
 {
  std::string Nome_File;
  std::cout << "In which file do you want to save the data (please write it all up, if file doesn't exist it will be created)?" << std::endl;
  std::cin >> Nome_File;
  std::fstream stream;
  stream.open (Nome_File, std::ios::out|std::ios::app);
  if (!stream)
   {std::cerr << "Cannot open the file" << std::endl; exit (0);} 
  stream << "Saved data is:" << std::endl << std::endl
         << data << std::endl << std::endl;
  std::cout << "File now has: " << stream.seekg (0, std::ios::end).tellg() << " bytes." << std::endl << std::endl;
  stream.close ();
 }

//Print_sol method definirion:
void matrixop::print_sol (double *vet)
 {
  std::string Nome_File;
  std::cout << "In which file do you want to save the data (please write it all up, if file doesn't exist it will be created)?" << std::endl;
  std::cin >> Nome_File;
  std::fstream stream;
  stream.open (Nome_File, std::ios::out|std::ios::app);
  if (!stream)
   {std::cerr << "Cannot open the file" << std::endl; exit (0);}
   stream << "Saved linear system solutions are:" << std::endl << std::endl;
    for (int i=0; i<a; i++)
      stream << std::setprecision (2) << std::setw (6) <<"x[" <<i+1 <<"] = " << vet[i] << " " << std::endl << std::endl;
  std::cout << "File now has: " << stream.seekg (0, std::ios::end).tellg() << " bytes." << std::endl << std::endl;
  stream.close ();
 }

//Rank method definition:
void matrixop::rank ()
 {
  //Delete elements under diagonal: 
  for (int j=0; j<a-1; j++)
   for (int i=j+1; i<a; i++)
    {
     double div = k[i][j]/k[j][j];
      if (k[j][j]==0)
       {break;}
      else
       {
        for (int m=0; m<a; m++) mtr[m] = div*k[j][m];
        for (int m=0; m<a; m++) k[i][m] -= mtr[m];
       }
    }

  //Output A matrix:
  std::cout <<"Delete elements under diagonal:" << std::endl;
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     {std::cout << std::setprecision (2) << std::setw (6) << k[i][j] << " ";}
       std::cout << std::endl;
   }
    std::cout << std::endl;

   //Calculare matrix A rank:
   rg=a;
   for (int i=0; i<a; i++)	 
      {
      if (k[i][i]!=0)
       rg-=0;
      else if (k[i][i]==0)
       rg-=1;
      }
    std::cout << "Matrix A rank is: " << rg << std::endl;
 }

//Matrix_norm method definition:
void matrixop::matrix_norm ()
 {
  //Norm 1.
  v = new double [a];
   for (int m=0; m<a; m++)
    v[m] = 0;

   for (int j=0; j<a; j++)
    for (int i=0; i<a; i++)
     v[j] += fabs(k[i][j]);
  norm_1 = MaxPtr <double> (v,a); 
  std::cout << "||A||1 matrix norm is: " << std::setprecision (4) << norm_1 << std::endl;

  //Norm ∞.
   for (int m=0; m<a; m++)
    v[m] = 0;

   for (int i=0; i<a; i++)
    for (int j=0; j<a; j++)
     v[i] += fabs(k[i][j]);
  norm_2 = MaxPtr <double> (v,a);
  std::cout << "||A||∞ matrix norm is: " << std::setprecision (4) << norm_2 << std::endl;
 
  //Frobenius norm.
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)			
     w[j][i] = k[i][j];
   }

  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     I[i][j]=0;
   }

  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     for(int h=0; h<a ;h++)
      I[i][j]+=k[i][h]*w[h][j];
   }

  t=0;
  for (int i=0; i<a; i++)
   t += I[i][i];

   norm_3 = sqrt(t);
  std::cout << "||A||2 Frobenius norm is: " << std::setprecision (4) << norm_3 << std::endl << std::endl;
 }

//Zero method definition:
double matrixop::zero ()
 {
  v = new double [a];
   for (int m=0; m<a; m++)
    v[m] = 0;

   for (int j=0; j<a; j++)
    for (int i=0; i<a; i++)
     v[j] += fabs(k[i][j]);
  norm_1 = MaxPtr <double> (v,a); 
  zero_ = norm_1 / 10000000000;
  return zero_;
 }

