#include <iostream>

#include "../include/matrixop.h"

using namespace std;

int main ()
 {
  int choice;
  char word;
  cout << "Enter an option number:" << endl
       << "NOTE: all the following operations are available only for square matrices." << endl
       << "1: quit the program." << endl
       << "2: matrix inversion through Gauss algorithm." << endl
       << "3: matrices sum." << endl
       << "4: matrices difference." << endl
       << "5: matrix trace." << endl
       << "6: matrix determinant." << endl
       << "7: row by column matrix product." << endl
       << "8: linear sistem resolutiomn through inverse method." << endl
       << "9: matrix transpose and simmetry check. " << endl
       << "10: matrix rank." << endl
       << "11: matrix norm." << endl;
  cin >> choice;
   if (choice==2)
    {
     matrixop A(1);
      cout << A;
      A.inverse ();
     cout << "Do you want to save the matrix on a file (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_I (A.I);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout << "Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==1)
    {
     cout <<"Program exited successfully." << endl,
     exit(0);
    }

   else if (choice==3)
    {
     matrixop A(1);
      cout << A;
     matrixop B(1);
      cout << B;
     if (A.a != B.a)
      {cerr << "The two matrices have to have the same order!" << endl << endl; main ();}
     cout << "Summed matrices:" << endl;
     A+=B;
     B.reset ();
     B=A;
     cout << B;
     cout << "Do you want to save the matrix on a file (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_I (B.k);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout <<"Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word=='n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==4)
    {
     matrixop A(1);
      cout << A;
     matrixop B(1);
      cout << B;
     if (A.a != B.a)
      {cerr << "The two matrices have to have the same order!" << endl << endl; main ();}
     cout << "Subtracted matrices:" << endl;
     A-=B;
     B.reset ();
     B=A;
     cout << B;
     cout << "Do you want to save the matrix on a file (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_I (B.k);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout <<"Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word=='n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==5)
    {
     matrixop A(1);
      cout << A;
      A.trace ();
     cout << "Do you want to save the data (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_data (A.t);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout << "Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==6)
    {
     matrixop A(1);
      cout << A;
      A.determinant ();
     cout << "Do you want to save the data (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_data (A.d);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout << "Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==7)
    {
     matrixop A(1);
      cout << A;
     matrixop B(1);
      cout << B;
     if (A.a != B.a)
      {cerr << "The two matrices have to have the same order!" << endl << endl; main ();}
     cout << "Product matrix:" << endl;
     A*=B;
     B.reset ();
     B=A;
     cout << "Do you want to save the matrix on a file (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      B.print_I (B.I);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout <<"Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word=='n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==8)
    {
     cout <<"Given the Ax=B linear system, enter matrix A to verify if it is invertible. "
          <<"If yes solution is unique, otherwise system has no solution:" << endl;
     matrixop A(1);
      A.linear_system ();
     cout << "Do you want to save the solution (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_sol (A.V);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout << "Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==9)
    {
     matrixop A(1);
      cout << A;
      A.transpose ();
     cout << "Do you want to save the matrix on a file (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_I (A.w);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout << "Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==10)
    {
     matrixop A(1);
      cout << A;
      A.rank ();
     cout << "Do you want to save the data (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_data (A.rg);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout << "Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else if (choice==11)
    {
     matrixop A(1);
      cout << A;
      A.matrix_norm ();
     cout << "Do you want to save the data (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Operation performed successfully." << endl << endl;
     else if (word=='y')
      A.print_data (A.norm_1),
      A.print_data (A.norm_2),
      A.print_data (A.norm_3);
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
     cout << "Do you want to run another operation (enter y o n)?",
     cin >> word,
     cout << endl;
     if (word == 'n')
      cout <<"Program exited successfully." << endl,
      exit(0);
     else if (word=='y')
      main();
     else 
      {cerr << "Command not found. Program aborts." << endl; exit (0);}
    }

   else
    {
     cout << "Command not found." << endl << endl; main ();
    } 

 }
