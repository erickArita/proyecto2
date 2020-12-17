#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>

using namespace std;

//Variables para moverse en los menus.
int opcion;
bool volver = false;

void gotoxy(int x, int y)
{
    HANDLE horizontal;
    horizontal = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(horizontal, Pos);
}

struct empleado
{
    int num_empleado;
    char nombre[20];
    char apellido[20];
    char puesto[10];
    float salario_actual;
    float salario_ant;
    char estado[10];

} empleado;

struct planilla
{
    int num_planilla;
    int mes;
    int anio;
    int num_empleado;
    char puesto[10];
    float sueldo;

} planilla;

void menu_empleados();
void menu_planillas();

int main()
{
    do
    {
        system("color 9");
        system("cls");
        gotoxy(46, 5);
        cout << "*-*-M E N U   P R I N C I P A L-*-*" << endl;
        gotoxy(50, 7);
        cout << "1. Archivo Empleados" << endl;
        gotoxy(50, 8);
        cout << "2. Archivo Planillas" << endl;
        gotoxy(50, 9);
        cout << "3. Salir" << endl;
        gotoxy(50, 12);
        cout << "Elija su opcion ( )" << endl;
        gotoxy(67, 12);
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            opcion == false;
            menu_empleados();
            break;

        case 2:
            opcion == false;
            menu_planillas();
            break;

        case 3:
            gotoxy(49, 13);
            cout << "Saliendo del Programa..." << endl;
            system("pause");
            exit(1);
            break;

        default:
            gotoxy(50, 13);
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            opcion = true;
            break;
        }

    } while (opcion == true || volver == true);

    return 0;
}

//Empieza menu empleados
void nuevo_empleado();
void buscar_empleado();

void archivo_empleados()
{
    ifstream archivo("empleados.txt");

    if (!archivo)
    {
        ofstream empleados;

        empleados.open("empleados.txt", ios::out); //Crea el archivo empleados.txt si aun no existe.

        if (empleados.fail())
        {
            cout << "\nNo se pudo crear el archivo" << endl;
            exit(1);
        }
        cout << "Archivo de Empleados creado." << endl;

        for (int i = 1; i <= 1000; i++)
        {
            empleados.write((char *)&empleado, sizeof(struct empleado));
        }

        empleados.close();
    }

    archivo.close();
}

void menu_empleados()
{
    archivo_empleados();
    system("cls");
    system("color 2");
    do
    {
        gotoxy(46, 5);
        cout << "*-*-A R C H I V O  E M P L E A D O S-*-*" << endl;
        gotoxy(50, 7);
        cout << "1. Ingresar Nuevo empleado" << endl;
        gotoxy(50, 8);
        cout << "2. Buscar por Codigo" << endl;
        gotoxy(50, 9);
        cout << "3. Buscar por nombre" << endl;
        gotoxy(50, 10);
        cout << "4. Modificar Puesto de empleado" << endl;
        gotoxy(50, 11);
        cout << "5. Modificar Sueldo de empleado" << endl;
        gotoxy(50, 12);
        cout << "6. Listar empleados" << endl;
        gotoxy(50, 13);
        cout << "7. Cambiar estatus de empleado activo/inactivo" << endl;
        gotoxy(50, 14);
        cout << "8. Salir" << endl;
        gotoxy(50, 15);
        cout << "Elija su opcion ( )" << endl;
        gotoxy(67, 15);
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            opcion == false;
            nuevo_empleado();
            break;

        case 2:
            opcion == false;
            buscar_empleado();
            break;

        case 3:
            opcion == false;

            break;

        case 4:
            opcion == false;

            break;

        case 5:
            opcion == false;

            break;

        case 6:
            opcion == false;

            break;

        case 7:
            opcion == false;

            break;

        case 8:
            gotoxy(49, 16);
            cout << "Volviendo al menu principal..." << endl;
            system("pause");
            volver = true;
            break;

        default:
            gotoxy(50, 16);
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            opcion = true;
            break;
        }

    } while (opcion == true && volver == false);
}
void nuevo_empleado()
{
}
void buscar_empleado()
{
}

//Empieza menu Planillas
void archivo_planillas()
{

    ifstream archivo("planillas.txt");

    if (!archivo)
    {
        ofstream planillas;

        planillas.open("planillas.txt", ios::out); //Crea el archivo planillas.txt si aun no existe.

        if (planillas.fail())
        {
            cout << "\nNo se pudo crear el archivo" << endl;
            exit(1);
        }

        for (int i = 1; i <= 1000; i++)
        {
            planillas.write((char *)&planilla, sizeof(struct planilla));
        }

        planillas.close();
    }

    archivo.close();
}

void menu_planillas()
{
    system("cls");
    system("color 6");
    do
    {
        gotoxy(46, 5);
        cout << "*-*-A R C H I V O  P L A N I L L A S-*-*" << endl;
        gotoxy(50, 7);
        cout << "1. Generar planilla" << endl;
        gotoxy(50, 8);
        cout << "2. Ver planilla" << endl;
        gotoxy(50, 9);
        cout << "3. Buscar por codigo de empleado" << endl;
        gotoxy(50, 10);
        cout << "(Muestra los pagos de un mismo empleado)" << endl;
        gotoxy(50, 11);
        cout << "4. Salir" << endl;
        gotoxy(50, 12);
        cout << "Elija su opcion ( )" << endl;
        gotoxy(67, 12);

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            opcion == false;

            break;

        case 2:
            opcion == false;

            break;

        case 3:
            opcion == false;

            break;

        case 4:
            gotoxy(49, 13);
            cout << "Volviendo al menu principal..." << endl;
            system("pause");
            volver = true;
            break;

        default:
            gotoxy(50, 13);
            cout << "Opcion no valida" << endl;
            system("pause");
            system("cls");
            opcion = true;
            break;
        }

    } while (opcion == true && volver == false);
}






























