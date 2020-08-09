#include <iostream>
#include <fstream>

void guardarDatos ();
void leerDatos ();
using namespace std;


int main()
{
  int opcion ;
  do{
   cout<<"\n*********************************************\n";
   cout<<"Asociacion de Vinicultores - Precios uva\n\n";
   cout<<"Opcion 1: Registrar datos\n";
   cout<<"Opcion 2: Leer datos\n";
   cout<<"Opcion 3: Salir\n";
   cout<<"Seleccione una opcion : ";
   cin>>opcion;
   cin.ignore();

   cout<<"\n*********************************************\n";
   switch (opcion ){

   case 1 :
   {
     guardarDatos ();
     break;
   }
   case 2 :
   {
   
    leerDatos ();  
    break ; 
   }
   case 3: 
   {
     cout<<"Salio del programa \n";
     break;
   }
   default:{
        cout<<"Opcion no valida intentelo de nuevo "<<endl;
    }
   }
  }while (opcion!=3);
 return 0;
   
}

void guardarDatos(){

  char tipoUva;
  int tamanioUva;
  double precioUva;
  int kilosUva;
  double gananciaUva;
  char d;
  ofstream Drago; // se creo un objeto en ofstream, aqui lo definimos como archivo, para luego abrirlo e ingresar datos
   
  Drago.open("datos.txt",ios::app);//la terminacion ".c_str()" determina como constante a este nombre del archivo
  do
    {
    cout<<"\t Digite los kilos de Uva : ";
    cin >> kilosUva;
    cout<<"\t Digite el precio por kilo : ";
    cin >> precioUva;
    cout<<"\t Indique el tipo de uva A o B : ";
    cin >>tipoUva;
    if (tipoUva == 'A'){
      cout<<"\t Indique el tamanio de uva 1 o 2 : ";
      cin >> tamanioUva;
      if (tamanioUva == 1){
        precioUva = precioUva + 0.20;
      }
      if (tamanioUva == 2){
        precioUva = precioUva + 0.30;
      }
    }

    if (tipoUva == 'B'){
      cout<<"\t Indique el tamanio de uva 1 o 2 : ";
      cin >> tamanioUva;
      if (tamanioUva == 1){
        precioUva = precioUva - 0.30;
      }
      if (tamanioUva == 2){
        precioUva = precioUva - 0.50;
      }
    }

    gananciaUva = precioUva * kilosUva;

    Drago << kilosUva << " " << precioUva << " " << tipoUva << " " << tamanioUva << " " << gananciaUva <<  "\n"; // Se deben registrar los datos en el archivo creado

    cout<<"Desea ingresar mas datos s/n : ";
    cin>>d;

    cin.ignore();//Se utiliza cin.ignore() para ignorar en este caso la actividad que produce el enter
  }while(d=='s');

   Drago.close(); //Todo archivo abierto se debe cerrar

  
}



void leerDatos (){
  char tipoUva;
  int tamanioUva;
  double precioUva;
  int kilosUva;
  double gananciaUva;
     
  ifstream archivolectura("datos.txt"); //se utiliza el ifstream para leer el archivo
  string texto;
  while(!archivolectura.fail())
  {
      
    archivolectura>>kilosUva>>precioUva>>tipoUva>>tamanioUva>>gananciaUva;

    if(!archivolectura.eof())
    {
      getline(archivolectura,texto);
      cout << "------------------------------------------\n";
      cout<<"Kilos : "<<kilosUva<<" kg \n";
      cout<<"Precio de uva por kilo : "<<precioUva<<" $ \n";
      cout<<"Tipo : "<<tipoUva<<"\n";
      cout<<"Tamanio : "<<tamanioUva<<"\n";
      cout<<"Ganacia total : "<<gananciaUva<<" $ \n";
      cout << "------------------------------------------\n";

    }

  }
  archivolectura.close(); 
}