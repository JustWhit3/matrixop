//CORPO DELLA CLASSE MATRICE.
class Matrice
 {
  public:
   Matrice () {};
   Matrice (int);
   ~Matrice ();

   void Inversa ();
   void Azzera ();
   void Traccia ();
   void Determinante ();
   void Sistema_Lineare ();
   void Trasposta ();
   void Stampa_I (double **ptr);
   void Stampa_Dato (double dato);
   void Stampa_Sol (double *vet);
   void Rango ();
   void Norma_Matriciale ();
   double Zero ();

   const Matrice& operator += (const Matrice &A);
   const Matrice& operator -= (const Matrice &A);
   const Matrice& operator *= (const Matrice &A);

   double t, d, rg, Norma_1, Norma_2, Norma_3, zero;
   double **k, **w, **I, **S, *mtr, *v, *V;
   int a;
 };

//DEFINIZIONE COSTRUTTORE PRINCIPALE.
Matrice::Matrice (int)
 {
  cout << "Inserisci l'ordine della matrice: " << endl;
  cin >> a;
   if (a<=0)
    {cerr << "L'ordine della matrice deve essere un intero positivo!" << endl; exit(0);}

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

    cout << "Inserire gli elementi della matrice: " << '\n';
    for (int i=0; i<a; i++)
     for (int j=0; j<a; j++)
      {cout << "Elemento di posizione (" << i+1 << "," << j+1 <<") ";
       cin >> k[i][j];}
       cout << endl;
    for (int i=0; i<a; i++)
    {for (int j=0; j<a; j++)			
      w[i][j] = k[i][j];} 
 }

//DEFINIZIONE DISTRUTTORE.
Matrice::~Matrice ()
 {
  for(int i=0;i<a;i++) {delete I[i];delete k[i];}
  for(int i=0;i<a;i++) delete w[i]; 
  for(int i=0;i<a;i++) delete S[i]; 
  delete I, k, w, mtr, v, V, S;
 }

//DEFINIZIONE METODO CHE STAMPA L'INVERSA DI UNA MATRICE.
void Matrice::Inversa ()
 {
  //La affianco alla sua matrice identità.
  for (int i=0; i<a; i++)
  {
   for (int j=0; j<(2*a); j++)
    if (j>=a)
    {if (j!=i+a)
      w[i][j]=0;
     else if (j==i+a)
      w[i][j]=1;}
  }

  //Controllo gli zeri sulla diagonale.
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

  //Elimino gli elementi sotto la diagonale. 
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

  //Controllo il determinante.
  d = 1;
  for (int i=0; i<a; i++)
   {d = d*w[i][i];}
    if (d<=Zero() & d>=-Zero()) 
     {cout << "Il determinante è nullo, la matrice non è invertibile. " << '\n'; exit(0);} 
    else
     {cout << "Il determinante è: " << d << " ,la matrice è dunque invertibile." << '\n' << '\n';}

  //Elimino gli elementi sopra la diagonale.
  for (int j=a-1; j>0; j--)
  {for (int i=j-1; i>=0; i--)
   {double div = w[i][j]/w[j][j];
     for (int m=0; m<(2*a) ;m++) mtr[m] = div*w[j][m];
     for (int m=0; m<(2*a) ;m++) w[i][m] -= mtr[m];
   }
  }

  //Divido ogni riga per il pivot.
  for (int i=0; i<a; i++) 
   if (w[i][i]!=1) 
   {double div = w[i][i];
    for (int m=0; m<(2*a); m++) 
     w[i][m] = w[i][m]/div;}

  //Stampa matrice inversa.
  {for (int i=0; i<a; i++) 
   {for (int m=0, j=a; j<(2*a); j++, m++)
    I[i][m] = w[i][j];}
  }
  cout << "Eccoti la matrice inversa: " << '\n';
  for (int i=0; i<a; i++)
   {for (int j=0; j<a; j++)
    {cout << setprecision (2) << setw (6) << I[i][j] << " ";}
     cout << '\n';}
     cout << '\n';
 }

//DEFINIZIONE METODO CHE AZZERA LA MATRICE.
void Matrice::Azzera ()
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

//DEFINIZIONE METODO PER LA TRACCIA DI UNA MATRICE.
void Matrice::Traccia ()
 {
  t=0;
  for (int i=0; i<a; i++)
   t += w[i][i];
  cout << "La traccia della matrice è: " << t <<'\n';
 }

//DEFINIZIONE METODO PER IL DETERMINANTE DI UNA MATRICE.
void Matrice::Determinante ()
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
    {cout << "Il determinante è: " << d << '\n';}
 }

//DEFINIZIONE METODO PER LA RISOLUZIONE DI UN SISTEMA LINEARE:
void Matrice::Sistema_Lineare ()
 {
  Inversa ();
  cout << "La soluzione del sistema è unica, quindi posso inserire le coordinate del vettore B:" << endl << endl;
  v = new double [a];
  V = new double [a];
  cout << "Inserire gli elementi del vettore di dimensione " << a << ": " << '\n';
   for (int i=0; i<a; i++)
    {cout << "Elemento di posizione " << i+1 << ": ";
       cin >> v[i];}
       cout << endl;
  cout << "Eccoti il vettore B: " << endl;
    for (int i=0; i<a; i++)
      {cout << setprecision (2) << setw (6) << v[i] << " " << endl;}
       cout << endl;
  cout << "Le soluzioni del sistema lineare sono:" << endl;
   for (int i=0; i<a; i++)
    V[i]=0;
   for (int i=0; i<a; i++)
    for (int j=0; j<a ;j++)
     V[i]+=I[i][j]*v[j];
   for (int i=0; i<a; i++)
      {cout << setprecision (2) << setw (6) <<"x[" <<i+1 <<"] = " << V[i] << " " << endl;}
       cout << endl;
 }

//DEFINIZIONE METODO PER LA TRASPOSTA DI UNA MATRICE:
void Matrice::Trasposta ()
 {
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)	
     w[j][i] = k[i][j];
   }
  cout << "Eccoti la trasposta: " << endl;
    for (int i=0; i<a; i++)
     {for (int j=0; j<a; j++)
      {cout << setprecision (2) << setw (6) << w[i][j] << " ";}
       cout << endl;}
    cout << endl;
 }

//RIDEFINIZIONE OPERATORE +=.
const Matrice &Matrice::operator += (const Matrice &A)
 {
  for (int i=0; i<(A.a); i++)
   for (int j=0; j<(A.a); j++)
    k[i][j] += A.k[i][j];
  return *this;
 }

//RIDEFINIZIONE OPERATORE -=.
const Matrice &Matrice::operator -= (const Matrice &A)
 {
  for (int i=0; i<(A.a); i++)
   for (int j=0; j<(A.a); j++)
    k[i][j] -= A.k[i][j];
  return *this;
 }

//RIDEFINIZIONE OPERATORE *=.
const Matrice &Matrice::operator *= (const Matrice &A)
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
  cout << "Eccoti il prodotto righe per colonne tra le due matrici: " << '\n';
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     {cout << setprecision (2) << setw (6) << I[i][j] << " ";}
      cout <<'\n';}
    cout <<'\n';
  return *this;
 }

//RIDEFINIZIONE OPERATORE <<.
ostream& operator << (ostream& os, Matrice &A)
 {
  cout << "Eccoti la matrice: " << endl;
  int a;
    for (int i=0; i<a; i++)
     {for (int j=0; j<a; j++)
      {os << setprecision (2) << setw (6) << A.k[i][j] << " ";}
       os << endl;}
    os << endl;
  return os;
 }

//DEFINIZIONE METODO PER STAMPARE UNA MATRICE SU FILE:
void Matrice::Stampa_I (double **I)
 {
  string Nome_File;
  cout << "Su quale file vuoi salvare il dato ottenuto (scrivere tutto attaccato, se il file non esiste verrà creato)?" << endl;
  cin >> Nome_File;
  fstream stream;
  stream.open (Nome_File, ios::out|ios::app);
  if (!stream)
   {cerr << "Impossibile aprire il file." << endl; exit (0);}
   stream << "La matrice salvata è:" << endl << endl;
    for (int i=0; i<a; i++)
     {for (int j=0; j<a; j++)
      {stream << setprecision (2) << setw (6) << I[i][j] << " ";}
       stream << endl;}
    stream << endl;
  cout << "Il file ora contiene: " << stream.seekg (0, ios::end).tellg() << " bytes." << endl <<endl;
  stream.close ();
 }

//DEFINIZIONE METODO PER STAMPARE UN DATO SU FILE:
void Matrice::Stampa_Dato (double dato)
 {
  string Nome_File;
  cout << "Su quale file vuoi salvare il dato ottenuto (scrivere tutto attaccato, se il file non esiste verrà creato)?" << endl;
  cin >> Nome_File;
  fstream stream;
  stream.open (Nome_File, ios::out|ios::app);
  if (!stream)
   {cerr << "Impossibile aprire il file." << endl; exit (0);} 
  stream << "Il dato salvato è:" << endl << endl
         << dato << endl << endl;
  cout << "Il file ora contiene: " << stream.seekg (0, ios::end).tellg() << " bytes." << endl <<endl;
  stream.close ();
 }

//DEFINIZIONE METODO PER STAMPARE UN VETTORE SU FILE:
void Matrice::Stampa_Sol (double *vet)
 {
  string Nome_File;
  cout << "Su quale file vuoi salvare il dato ottenuto (scrivere tutto attaccato, se il file non esiste verrà creato)?" << endl;
  cin >> Nome_File;
  fstream stream;
  stream.open (Nome_File, ios::out|ios::app);
  if (!stream)
   {cerr << "Impossibile aprire il file." << endl; exit (0);}
   stream << "Le soluzioni del sistema lineare salvate sono:" << endl << endl;
    for (int i=0; i<a; i++)
      stream << setprecision (2) << setw (6) <<"x[" <<i+1 <<"] = " << vet[i] << " " << endl << endl;
  cout << "Il file ora contiene: " << stream.seekg (0, ios::end).tellg() << " bytes." << endl <<endl;
  stream.close ();
 }

//DEFINIZIONE METODO PER IL RANGO DI UNA MATRICE.
void Matrice::Rango ()
 {
  //Elimino gli elementi sotto la diagonale. 
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

  //Mando in output la matrice A.
  cout <<"Elimino gli elementi sotto la diagonale:" <<'\n';
  for (int i=0; i<a; i++)
   {
    for (int j=0; j<a; j++)
     {cout << setprecision (2) << setw (6) << k[i][j] << " ";}
       cout <<'\n';
   }
    cout <<'\n';

   //Calcolo il rango della matrice A.
   rg=a;
   for (int i=0; i<a; i++)	 
      {
      if (k[i][i]!=0)
       rg-=0;
      else if (k[i][i]==0)
       rg-=1;
      }
    cout << "Il rango della matrice è: " << rg <<'\n';
 }

//DEFINIZIONE METODO PER IL CALCOLO DELLA NORMA MATRICIALE.
void Matrice::Norma_Matriciale ()
 {
  //Norma 1.
  v = new double [a];
   for (int m=0; m<a; m++)
    v[m] = 0;

   for (int j=0; j<a; j++)
    for (int i=0; i<a; i++)
     v[j] += fabs(k[i][j]);
  Norma_1 = MaxPtr <double> (v,a); 
  cout << "La norma matriciale ||A||1 è: " << setprecision (4) << Norma_1 << endl;

  //Norma ∞.
   for (int m=0; m<a; m++)
    v[m] = 0;

   for (int i=0; i<a; i++)
    for (int j=0; j<a; j++)
     v[i] += fabs(k[i][j]);
  Norma_2 = MaxPtr <double> (v,a);
  cout << "La norma matriciale ||A||∞ è: " << setprecision (4) << Norma_2 << endl;
 
  //Norma di Frobenius.
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

   Norma_3 = sqrt(t);
  cout << "La norma matriciale di Frobenius ||A||2 è: " << setprecision (4) << Norma_3 << endl << endl;
 }

//DEFINIZIONE METODO PER SETTARE LO ZERO.
double Matrice::Zero ()
 {
  v = new double [a];
   for (int m=0; m<a; m++)
    v[m] = 0;

   for (int j=0; j<a; j++)
    for (int i=0; i<a; i++)
     v[j] += fabs(k[i][j]);
  Norma_1 = MaxPtr <double> (v,a); 
  zero = Norma_1 / 10000000000;
  return zero;
 }
