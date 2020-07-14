//INIZIO DELLA FUNZIONE MAIN PRINCIPALE
int main ()
 {
  int choice;
  char word;
  cout << "Digita un numero per scegliere quale operazione eseguire:" <<'\n'
       << "NOTA: Tutte le seguenti operazioni sono disponibili soltanto tra matrici quadrate dello stesso ordine." <<'\n'
       << "1: Termina il programma." <<'\n'
       << "2: Inversione di una matrice mediante l'algoritmo di Gauss." <<'\n'
       << "3: Somma di due matrici." <<'\n'
       << "4: Differenza tra due matrici." <<'\n'
       << "5: Traccia di una matrice." <<'\n'
       << "6: Determinante di una matrice." <<'\n'
       << "7: Prodotto righe per colonne tra due matrici." <<'\n'
       << "8: Risoluzione di un sistema lineare mediante il metodo dell'inversa." <<'\n'
       << "9: Trasposta di una matrice e verifica di simmetria. " << '\n'
       << "10: Rango di una matrice." <<'\n'
       << "11: Norma Matriciale." <<'\n';
  cin >> choice;
   if (choice==2)
    {
     Matrice A(1);
      cout << A;
      A.Inversa ();
     cout << "Vuoi stampare la matrice su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_I (A.I);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout << "Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==1)
    {
     cout <<"Programma terminato con successo." <<'\n',
     exit(0);
    }

   else if (choice==3)
    {
     Matrice A(1);
      cout << A;
     Matrice B(1);
      cout << B;
     if (A.a != B.a)
      {cerr << "Le due matrici devono avere ordine uguale!" << endl << endl; main ();}
     cout << "Matrici sommate:" << endl;
     A+=B;
     B.Azzera ();
     B=A;
     cout << B;
     cout << "Vuoi stampare la matrice su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_I (B.k);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout <<"Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word=='n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==4)
    {
     Matrice A(1);
      cout << A;
     Matrice B(1);
      cout << B;
     if (A.a != B.a)
      {cerr << "Le due matrici devono avere ordine uguale!" << endl << endl; main ();}
     cout << "Matrici sottratte:" << endl;
     A-=B;
     B.Azzera ();
     B=A;
     cout << B;
     cout << "Vuoi stampare la matrice su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_I (B.k);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout <<"Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word=='n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==5)
    {
     Matrice A(1);
      cout << A;
      A.Traccia ();
     cout << "Vuoi stampare il dato ottenuto su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_Dato (A.t);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout << "Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==6)
    {
     Matrice A(1);
      cout << A;
      A.Determinante ();
     cout << "Vuoi stampare il dato ottenuto su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_Dato (A.d);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout << "Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==7)
    {
     Matrice A(1);
      cout << A;
     Matrice B(1);
      cout << B;
     if (A.a != B.a)
      {cerr << "Le due matrici devono avere ordine uguale!" << endl << endl; main ();}
     cout << "Prodotto eseguito:" << endl;
     A*=B;
     B.Azzera ();
     B=A;
     cout << "Vuoi stampare la matrice su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      B.Stampa_I (B.I);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout <<"Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word=='n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==8)
    {
     cout <<"Dato il sistema lineare Ax=B, inserisci la matrice A per verificare se è invertibile. "
          <<"In caso positivo la soluzione è unica, altrimenti il sistema non ha soluzioni:" << endl;
     Matrice A(1);
      A.Sistema_Lineare ();
     cout << "Vuoi stampare le soluzioni su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_Sol (A.V);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout << "Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==9)
    {
     Matrice A(1);
      cout << A;
      A.Trasposta ();
     cout << "Vuoi stampare la matrice su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_I (A.w);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout << "Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==10)
    {
     Matrice A(1);
      cout << A;
      A.Rango ();
     cout << "Vuoi stampare il dato ottenuto su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_Dato (A.rg);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout << "Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else if (choice==11)
    {
     Matrice A(1);
      cout << A;
      A.Norma_Matriciale ();
     cout << "Vuoi stampare il dato ottenuto su un file (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Operazione eseguita con successo." <<'\n' <<'\n';
     else if (word=='s')
      A.Stampa_Dato (A.Norma_1),
      A.Stampa_Dato (A.Norma_2),
      A.Stampa_Dato (A.Norma_3);
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
     cout << "Vuoi eseguire qualche altra operazione (digitare s o n)?",
     cin >> word,
     cout <<'\n';
     if (word == 'n')
      cout <<"Programma terminato con successo." <<'\n',
      exit(0);
     else if (word=='s')
      main();
     else 
      {cerr << "Comando non trovato. Programma terminato." << endl; exit (0);}
    }

   else
    {
     cout << "Comando non trovato." << endl << endl; main ();
    } 

 }
