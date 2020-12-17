#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct usuario
{
    int id;
    char nombre[20];
    float capital;
    int ganadas;
    int perdidas;
 
    void escribir()
    {
        cout << " " << id << " " << nombre << " " << capital << " " << ganadas << " " << perdidas;
    }
} newUser;

void buscarUsuario()
{

    int id;
    cout << "Ingrese el id de un usuario " << endl;
    cin >> id;

    ifstream archivo("juego.txt");
    if (archivo.fail())
    {
        cout << "No se puedo leer el archivo" << endl;
    }
    while (!archivo.eof())
    {
        archivo.read((char *)&newUser, sizeof(struct usuario));
        if (newUser.id == id)
        {
            newUser.escribir();
            break;
        }
    }

    archivo.close();
}

void escribir()
{

    cout << "Ingrese los valores de un juego separados por un espacio " << endl;
    ofstream archivo("juego.txt"); //para agregarle al archivo
    cin >> newUser.id;
    cin >> newUser.nombre;
    cin >> newUser.capital;
    cin >> newUser.ganadas;
    cin >> newUser.perdidas;
  
    archivo.seekp(newUser.id * sizeof(struct usuario), ios::beg);
    archivo.write((char *)&newUser, sizeof(struct usuario));
    archivo.close();
}
void crearArchivo(char nombre[])
{

    ifstream archivoExiste(nombre); //leo ese archivo para ver si existe
    if (!archivoExiste)             //si no existe lo creo al iniciar el programa
    {
        ofstream archivo(nombre); // creamos el archivo

        for (int i = 0; i < 1000; i++)
        {
            archivo.write((char *)&newUser, sizeof(struct usuario));
        }

        archivo.close();
    }
}

int main()
{

    crearArchivo("juego.txt");
    int i;
    cin >> i;
    if (i == 1)
    {

        escribir();
    }
    else
    {

        buscarUsuario();
    }

    return 0;
}