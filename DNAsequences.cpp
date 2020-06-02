#include<iostream> 
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

//ojo:Aqui empiezan las funciones para computos.

//************************************************************
double cgcontent(char p[],int s)//Funcion para calcular los cg content.
{
 int sumacg=0;
 double promediocg=0;
 for(int z=0;z<s;z++)
 {
  if(p[z]=='c'||p[z]=='g')
  {
   sumacg=sumacg+1;
  }
  else
  {
   sumacg=sumacg+0;
  }
 }
 promediocg=sumacg/(s*1.0);
 return(promediocg);
}
//**************************************************************

//**************************************************************
int polyT(char stringT[],int s, int polyN)//Funcion para poly-T
{
 int sumT=0;
 int sumTmax=0;
 for(int zT=0;zT<s;zT++)
 {
  if(stringT[zT]=='t')
  {
   sumT=sumT+1;
  }
  else
  {
   if(sumT>=polyN)
   {
    sumTmax=sumTmax+1;
    sumT=0;
   }
   else
   {
    sumT=0;
   }
  }
 }
 return(sumTmax);
}
//***************************************************************



int mutations (char dna1[], char dna2[], int length1, int length2)//Mutaciones
{
 int sum_Mut=0;
 int extraposition=0;
 int positionsdiffer=0;
 if(length1>length2)
 {
  extraposition=length1-length2;
  for(int kmut=0;kmut<length1;kmut++)
  {
   if(dna1[kmut]==dna2[kmut])
   {
    sum_Mut=sum_Mut+0;
   }
   else
   {
    sum_Mut=sum_Mut+1;
   }
  }
 }
 else if(length1<length2)
 {
  extraposition=length2-length1;//extrapositions no son necesarias ya que tomas el mayor length
  phylosamelength://lo usamos sabiendo que ambos tienen misma length***
  for(int kmut=0;kmut<length2;kmut++)
  {
   if(dna1[kmut]==dna2[kmut])
   {
    sum_Mut=sum_Mut+0;
   }
   else
   {
    sum_Mut=sum_Mut+1;
   }
  }
 } 
 else
 {
  goto phylosamelength;//ojo aqui es el caso de misma length ambos***
  extraposition=0; 
 }
 positionsdiffer=sum_Mut;//+extraposition;
 return (positionsdiffer);
}

//*************************************************************************

double phylogeneticdistance(char phylo1[], char phylo2[], int lengthphylo)//Phylodistance
{
 int sum_phylo=0;
 double phylodist=0;
 for(int kphylo=0;kphylo<lengthphylo;kphylo++)
 {
  if(phylo1[kphylo]==phylo2[kphylo])
  {
   sum_phylo=sum_phylo+0;
  }
  else
  {
   sum_phylo=sum_phylo+1;
  }
 }
 phylodist=sum_phylo/(lengthphylo*1.0);
 return(phylodist);
}
 






//ojo:Aqui comienza el main.Entradas y salidas desde aqui nomas.

int main()
{
 string firstdna, lastdna;
 int N=0;
 const int LENG=10;  //ojo aqui esta como tipo integer no string
 fstream inputStream;

 inputStream.open("dna.txt");

 if(inputStream.fail())
 {
  cerr<<"No se puede abrir el file dna.txt"<<endl;
  return 0;
 }
 else
 {
  const int LENGTH=4095;//Arbitrary length for assigment.  
  
  int j=0;//Used to count length of firstdna string.
  int l=0;//Used to count length of lastdna string.
  
  int extraletters=0;//Para calcular extra letters
  extraletters=l-j;//cuando se compute mutations
  
  int option=0;//Used to select in menu.


  inputStream>>firstdna;
  inputStream>>lastdna;

  cout<<"First dna : "<<firstdna<<endl; 
  cout<<"Second dna: "<<lastdna<<endl;

   for(int i=0;i<LENGTH;i++)
   {
    if((firstdna[i]!='a')&&(firstdna[i]!='c')&&(firstdna[i]!='t')&&(firstdna[i]!='g'))
    {
     cout<<"El first dna no es valido"<<endl;
     goto salida;
    }
    else
    {
     j=i+1;
     if(firstdna[j]=='\0')
     goto fin;
    }
   }

  fin:

   for(int k=0;k<LENGTH;k++)
   {
    if((lastdna[k]!='a')&&(lastdna[k]!='c')&&(lastdna[k]!='t')&&(lastdna[k]!='g'))
    {
     cout<<"El last dna no es valido"<<endl;
     goto salida;
    }
    else
    {
     l=k+1;
     if(lastdna[l]=='\0')
     goto fin2;
    }
   }

  fin2:

  cout<<"Longitud del firstdna is "<<j<<endl;
  cout<<"La longitud del lastdna is "<<l<<endl;
  cout<<firstdna[15]<<endl;  //aqui ya sabemos elementos de strings y longitudes
  cout<<lastdna[7]<<endl;   //solo firstName and lastName can use [i] si son string
  
  //Aqui convertimos en array char los string de dna ya validados.
  char firstdnastring[j+1];//ojo debo agregarle j+1 para el \0 null sino salen huevadas.
  for(int m=0;m<j+1;m++)
  {
   firstdnastring[m]=firstdna[m];
  }

  char seconddnastring[l];
  for(int n=0;n<l+1;n++)//ojo le agregaste ahora aqui n<l+1 por simbolos funny al final
  {
   seconddnastring[n]=lastdna[n];
  }

  cout<<"first dna: "<<firstdnastring<<endl;//Aqui ya comprobamos que son array char
  cout<<"last dna:  "<<seconddnastring<<endl<<endl;//ahora podemos trabajarlos para computos

  menu:

  cout<<"1   compute GC content of DNA string 1"<<endl;
  cout<<"2   compute GC content of DNA string 2"<<endl;
  cout<<"3   compute number of poly-T sequences of length N or more in DNA string 1"<<endl;
  cout<<"4   compute number of poly-T sequences of length N or more in DNA string 2"<<endl;
  cout<<"5   compute number of mutations between the two DNA strings"<<endl;
  cout<<"6   compute phylogenetic distance between the two DNA strings"<<endl;
  cout<<"7   quit"<<endl<<endl;
  cin>>option;

  //Comenzamos a llamar funciones y hacer computos.
  switch(option)
  {
   case 1:
        cout<<"CG content of DNA string 1: "<<cgcontent(firstdnastring,j)<<endl;
        
        break;
   case 2:
        cout<<"CG content of DNA string 2: "<<cgcontent(seconddnastring,l)<<endl;
        
        break;
   case 3:
        Nseconddna:
        cout<<"Ingresa valor de N: "<<endl;
        cin>>N;
        if(N<=0)
        {
         cout<<"Enter N greater than 0"<<endl;
         goto Nseconddna;
        }
        while(N<=0);
        {
         cout<<"Number of poly-T sequences are: "<<polyT(firstdnastring,j,N)<<endl;
        }
        
        break;
   case 4:
        Nfirstdna:
        cout<<"Ingresa valor de N: "<<endl;
        cin>>N;
        if(N<=0)
        {
         cout<<"Enter N greater than 0"<<endl;
         goto Nfirstdna;
        }
        else
        {
         cout<<"Number of poly-T sequences are: "<<polyT(seconddnastring,l,N)<<endl;
        }
        
        break;
   case 5:
        cout<<"The number of mutations between the two DNA strings is: "<<mutations(firstdnastring,seconddnastring,j,l)<<endl<<endl;
        
        break;
   case 6:
        cout<<"The phylogenetic distance between the two DNA strings is: "<<phylogeneticdistance(firstdnastring,seconddnastring,j)<<endl;


        break;
   case 7:
        goto salida;
        break;        
   default:
        cout<<"Invalid choice. Try again"<<endl;
  }
  

  if(firstdna[16]=='\0')
  {
   cout<<"EL firstdna termina en null '\0'"<<endl;
  }

  goto menu;

  inputStream.close();
 }
 salida:
 return 0;
}
