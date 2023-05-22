#include<iostream>      //Agregamos las librerias
#include<stdio.h>
#include<string>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include <iomanip> //Para la precision de decimales

using namespace std;            //Espacio de trabajo

struct INFO                     //Estructura y datos de la tienda
{
    int aniolanzamiento;
    string nombre, genero, clasificacion, consola, caracteristicas, descripcion, status;
    float impuesto = 1.16, total, precio;
};
int contador = 1, alta;         //Inicializacion para contador y la alta de videojuegos

INFO* datos;                    /*Puntero de datos hacia INFO
                                Datos reserva el espacio de memoria para la direccion de INFO*/
void ALTA();                    //Asinacion de funciones
void MODIFICACION();
void BAJA();
void LISTA();
void SALIR();

int main() {                     //Declaramos funcion principal

    while (true) {
        int opc = 0;                //Declaración de la opción

        printf("\t***Bienvenido a nuestra tienda de videojuegos***\n");                     //Titulo
        printf("1.-ALTA DE VIDEOJUEGO\n2.-MODIFICACI%cN DE ARTICULO\n3.-BAJA DE ARTICULO\n", 224);   // Opciones
        printf("4.-LISTA DE ARTICULOS\n5.-LIMPIAR PANTALLA\n6.-SALIR DEL PROGRAMA\n");
        printf("Por favor, pulse la tecla que requiera para ejecutar la acci%cn.\n", 162);   //Pregunta
        scanf_s("%d", &opc);        //Digita la opción

        switch (opc) {              //Ejecucion de opciones
        case 1:
            ALTA();
            system("pause");
            break;
        case 2:
            MODIFICACION();
            break;
        case 3:
            BAJA();
            break;
        case 4:
            LISTA();
            break;
        case 5:
            system("cls");
            break;
        case 6:
            SALIR();
            break;
        }

    }
}

void ALTA() {
    printf("Digite el N%cMERO de registros que desea a%cadir: ", 233, 164); //Pregunta al usuario
    scanf_s("%d", &alta);   //Digita el numero de registros
    datos = new INFO[alta]; /*new INFO: Crea un objeto de tipo INFO
    [alta] : Indica que se está creando un arreglo de tamaño alta que contiene objetos de tipo INFO
     datos : El puntero datos apunta al inicio del arreglo de objetos INFO*/

    if (alta < 1) {         //Si es menor a uno regresa
        printf("Opci%cn invalidada...\n", 162);
        return ALTA();
    }

    system("cls");

    for (int i = 0; i < alta; i++) {    //Posicion del arreglo debe empezar en 0 y menor a la alta

        printf("\nN%cMERO del articulo: ", 233);
        printf("%d", contador);
        printf("\nDigite el NOMBRE del videojuego: ");
        cin.ignore();
        getline(cin, datos[i].nombre);
        printf("\nDigite el A%cO de lanzamiento: ", 165);
        scanf_s("%d", &datos[i].aniolanzamiento);
        printf("\nDigite el GENERO del videojuego: ");
        cin.ignore();
        getline(cin, datos[i].genero);
        printf("\nDigite la CLASIFICACI%cN del videojuego: ", 224);
        getline(cin, datos[i].clasificacion);
        printf("\nDigite la CONSOLA del videojuego: ");
        getline(cin, datos[i].consola);
        printf("\nDigite las CARACTERISTICAS del videojuego: ");
        getline(cin, datos[i].caracteristicas);
        printf("\nDigite la DESCRIPCI%cN del videojuego: ", 224);
        getline(cin, datos[i].descripcion);
        printf("\nDigite el PRECIO unitario del videojuego (DIVISA EN PESO MEXICANO): ");
        scanf_s("%f", &datos[i].precio);
        printf("\nEl IMPUESTO es del 16%%\n"); //Recuerda que la impresion de porcentaje es doble
        datos[i].total = datos[i].precio * datos[i].impuesto;
        printf("\nEl TOTAL del articulo es de %.2fMXN\n", datos[i].total);  //Ajusta la presicion de 

        contador++;

        system("pause");
        system("cls");
    }
}

void MODIFICACION()
{
    int j = 0, opcion = 0, validacion; //Inicializacion
    do
    {
        printf("Digite el registro a modificar: ");
        scanf_s("%d", &j); //Al digitar la opcion se resta uno por la localizacion del arreglo
        j = j - 1; // esto debido a que i inicia en 0

        for (int i = j; i == j; i++)
        {
            if ((datos[i].status == "ELIMINADO"))
            {
                printf("REGISTRO ELIMINADO %d\n", i + 1);
                printf("\nDigite un registro valido \n");
                validacion = 1;
            }
            else
            {
                validacion = 2;
            }
        }
    } while (validacion == 1);      //Si es igual a 1 proporciona opciones
    printf("Digite lo que desea modificar:\n");
    printf("1.-Nombre,2.-A%co de lanzamiento,3.-Genero,4.-Clasificaci%cn\n", 164, 162);
    printf("5.-Consola,6.-Caracteristicas,7.-Descripci%cn,8.-precio\n", 162);
    scanf_s("%d", &opcion);

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)    //Para la posicion elegida
        {
            printf("DIGITE EL NOMBRE\n");
            cin.ignore();       //Para evitar los espacios
            getline(cin, datos[i].nombre);
        }
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n'); //se vacia el buffer o el espacio
            printf("DIGITE EL A%cO\n", 165);
            scanf_s("%d", &datos[i].aniolanzamiento);
        }
        break;
    case 3:
        for (int i = j; i == j; i++)
        {
            printf("DIGITE EL GENERO\n");
            cin.ignore();
            getline(cin, datos[i].genero);       
        }
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            printf("DIGITE LA CLASIFICACION\n");
            cin.ignore();
            getline(cin, datos[i].clasificacion);
        }
        break;
    case 5:
        for (int i = j; i == j; i++)
        {
            printf("DIGITE LA CONSOLA\n");
            cin.ignore();
            getline(cin, datos[i].consola);
        }
        break;
    case 6:
        for (int i = j; i == j; i++)
        {
            printf("DIGITE LAS CARACTERISTICAS\n");
            cin.ignore();
            getline(cin, datos[i].caracteristicas);
        }
        break;
    case 7:
        for (int i = j; i == j; i++)
        {
            printf("DIGITE LA DESCRIPCI%cN\n", 224);
            cin.ignore();
            getline(cin, datos[i].descripcion);
        }
        break;
    case 8:
        for (int i = j; i == j; i++)
        {
            printf("DIGITE EL PRECIO\n");
            scanf_s("%f", &datos[i].precio);
            datos[i].total = datos[i].precio * 1.16;
        }
        break;
    }
}

void BAJA() {
    int j = 0;
    printf("Digite el registro a eliminar: ");
    scanf_s("%d",&j);
    j = j - 1;
    for (int i = j; i == j; i++)    //Si es igual eliminalo
    {
        cout << "Eliminando registro\n" << j + 1 << endl;
        datos[i].status = "ELIMINADO";
    }
}

void LISTA() {
    contador = 1;
    for (int i = 0; i < alta; i++) {

        if (datos[i].status == "ELIMINADO") {
            printf("REGISTRO ELIMINADO\n");
        }
        else {
            printf("\nN%cMERO del articulo: %d", 233, contador);
            printf("\nNOMBRE del videojuego: %s", datos[i].nombre.c_str());
            printf("\nA%cO de lanzamiento: %d", 165, datos[i].aniolanzamiento);
            printf("\nGENERO del videojuego: %s", datos[i].genero.c_str());
            printf("\nCLASIFICACI%cN del videojuego: %s", 224, datos[i].clasificacion.c_str());
            printf("\nCONSOLA del videojuego: %s", datos[i].consola.c_str());
            printf("\nCARACTERISTICAS del videojuego: %s", datos[i].caracteristicas.c_str());
            printf("\nDESCRIPCI%cN del videojuego: %s", 224, datos[i].descripcion.c_str());
            printf("\nPRECIO unitario del videojuego (DIVISA EN PESO MEXICANO): %.2f", datos[i].precio);
            printf("\nEl IMPUESTO es del 16%%\n");
            printf("\nEl TOTAL del articulo es de %.2fMXN\n", datos[i].total);
            system("pause");
            contador++;
        }
    }
}


void SALIR() {
    ofstream archivo; //clase ifstream para leer archivos
    string nombrearchivo;
    int contador = 1,texto; //Para numeros enteros
    string texto2;  //Para textos o registros eliminados
    float texto3 = 0;

    nombrearchivo = "Tienda.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
        exit(1);
    }

    archivo << "REGISTRO" << "\t";
    archivo << "NOMBRE DEL VIDEOJUEGO" << "\t";
    archivo << "ANIO DE LANZAMIENTO" << "\t";
    archivo << "GENERO" << "\t";
    archivo << "CLASIFICACION" << "\t";
    archivo << "CONSOLA" << "\t";
    archivo << "CARACTERISTICAS" << "\t";
    archivo << "DESCRIPCION" << "\t";
    archivo << "PRECIO" << "\t";
    archivo << "IMPUESTO" << "\t";
    archivo << "TOTAL" << "\n";

    for (int i = 0; i < alta; i++)
    {
        if (datos[i].status == "ELIMINADO")
        {
            texto2 = "REGISTRO ELIMINADO ";
            texto = i;
            archivo << texto2 << texto << "\n";
        }
        else
        {
            texto = contador;
            archivo << texto << "\t" << "\t";
            texto2 = datos[i].nombre;
            archivo << texto2 << "\t" << "\t" << "\t" << "\t" << "\t";
            texto = datos[i].aniolanzamiento;
            archivo << texto << "\t " << "\t" << "\t";
            texto2 = datos[i].genero;
            archivo << texto2 << "\t " << "\t";
            texto2 = datos[i].clasificacion;
            archivo << texto2 << "\t " << "\t" << "\t";
            texto2 = datos[i].consola;
            archivo << texto2 << "\t " << "\t";
            texto2 = datos[i].caracteristicas;
            archivo << texto2 << "\t " << "\t" << "\t";
            texto2 = datos[i].descripcion;
            archivo << texto2 << "\t " << "\t";
            texto3 = datos[i].precio;
            archivo << fixed << setprecision(2) << texto3 << "\t " << "\t";
            texto3 = datos[i].impuesto;
            archivo << fixed << setprecision(2) << texto3 << "\t " << "\t";
            texto3 = datos[i].total;
            archivo << fixed << setprecision(2) << texto3 << "\t " << "\t";

            archivo << "\n";
            contador++;
        }
    }
    archivo.close();
    printf("Programa terminado");
    exit(1);
}

/*La función "SALIR" se encarga de escribir los registros almacenados en la estructura datos
en el archivo llamado "Tienda.txt". Si se produce algún error al abrir el archivo, se 
muestra un mensaje de error y el programa se termina. Al finalizar, se muestra un mensaje en
la consola y se sale del programa.*/