#include <iostream>
using namespace std;

//Autores: Anthony Arias y Kristel Salas
//Fecha de Inicio: 18-4-2021
//Última fecha de modificación: 22-4-2021


//Constructores pd: necesito que me diga qué más atributos le puedo poner a cada uno xd

struct administrador { //posible lista simple
    string nombre;
    int claveAdmin;
    administrador*sig;

    administrador(string n, int cA){
        nombre = n;
        claveAdmin = cA;
        sig = NULL;
    }
}*primerA;

struct profesor { //Lista doble con inserción al inicio
    string nombre;
    int carnetProfesor;
    profesor* sig;
    profesor* ant;

    profesor(string n, int cP){
        nombre = n;
        carnetProfesor = cP;
        sig = NULL;
        ant = NULL;
    }
}*primerP;

struct estudiante { //lista simple con insercion ordenada de lo que queramos, qué usamos?? xd
    string nombre;
    int edad;
    int carnetE;
    estudiante*sig;

    estudiante(string n, int e, int ce){
        nombre = n;
        edad = e;
        carnetE = ce;
        sig = NULL;
    }
}*primerE;

struct curso { // lista circular con insercion al final
    string nombre;
    string codigo;
    int creditos;
    curso*sig;

    curso (string n, string co, int cre){
        nombre = n;
        codigo = co;
        creditos = cre;
        sig = NULL;
    }
};

struct reuniones { //posible lista simple o doble??



};

//Funciones

void insertarAdmin(string n, int cA){
    administrador* nn = new administrador(n, cA);
    nn->sig = primerA;
    primerA = nn;
}


void insertarInicioProfesor(string n, int cP){//funcion para insertar profesores a la lista al inicio, recibe toda la info y crea el nodo
    profesor* nn = new profesor(n,cP);
    nn->sig = primerP;
    if(primerP != NULL)
        primerP->ant = nn;
    primerP = nn;
}

profesor* buscarProfe(int carnetP){//función para buscar profesor que recibe por parámetro el carnet único de este y devuelve el objeto
    profesor*temp = primerP;
    while(temp!= NULL){
        if(temp->carnetProfesor == carnetP)
            return temp;
        temp = temp->sig;
    }
return NULL;// no lo encontro
}

void modificarProfesor(int carnetP, int nc, string nn ){//función para modificar la info del profesor, recibe el carnet del profesor y los datos nuevos a modificar
    profesor* nodoBuscado= buscarProfe(carnetP);
    if(nodoBuscado == NULL)
        cout<<"No encontrado, no se puede modificar";
    else
        nodoBuscado->nombre = nn;
        nodoBuscado->carnetProfesor = nc;

}

void imprimirProfesores(){//esto es nomas para probar luego se puede borrar
    profesor* temp = primerP;
    while(temp!= NULL){
        cout<<temp->nombre <<", " << temp->carnetProfesor << endl;
        temp = temp->sig;
    }
}

void insertarEstudiante(string n, int e, int c){//Inserta los estudiantes segun su edad de manera ascendente en el inicio
    estudiante*nn = new estudiante(n, e, c);
    estudiante*temp = primerE;
    nn->sig = primerE;
    primerE = nn; //ESTA MIERDA NO FUNCIONAAAAAAA O SEA SI PERO NO INSERTA POR EDAD ME CAGO EN SATANAS
}

void imprimirEstudiantes(){//para imprimir estudiantes se borra luego xd
    estudiante *temp = primerE;
    if (temp == NULL)
        cout << "lista vaciaaa";
    while(temp != NULL){
        cout<<temp-> nombre <<", " << temp-> edad <<", " << temp-> carnetE<< endl;
        temp = temp->sig;
    }
}

void imprimirAdmins(){//para imprimir admins se borra luego xd
    administrador *temp = primerA;
    while(temp != NULL){
        cout<<temp-> nombre <<", " << temp-> claveAdmin << endl;
        temp = temp->sig;
    }
}

// "frontend"

void menuAdmi(){
 cout << "1" <<endl;
 return;
}

void menuProf(){

int carnetP;
bool validacion = false;
while (validacion != true){
    cout << "\nPor favor ingrese su identificacion o digite 0 para volver\n-------------------------------------" << endl;
    cin >> carnetP;

    if (carnetP != 0){
        profesor* nodoBuscado = buscarProfe(carnetP);
        if(nodoBuscado == NULL)
        cout<<"\nERROR: El usuario no es valido\n";
        else {
            validacion = true;
            int opcion = -1;
            while (opcion != 0){
            cout << "\nBienvenido! \n-------------------------------------\n1- Consultar reuniones\n2- Consultar asitencia por reunionP\n3- Consultar cuales estudiantes asistieron a todas las reuniones\n0- Para salir\n-------------------------------------" << endl;
            cin >> opcion;
            switch(opcion){
                case 1:
                    //consultarReuniones();
                    break;
                case 2:
                    //consultarAsistenciaPorReu();
                    break;
                case 3:
                    //consultarAsitenciaTodasReu();
                    break;
                case 0:
                    //consultarTresAusencias();
                    break;
                default:
                    cout << "\nERROR: El valor no es valido\n" << endl;
                }
            }
        }
    }
    break;
}
return;
}

void menuEstu(){
cout << "2" <<endl;
return;
}


void menu(){
int opcion = -1;
while (opcion != 0){
  cout << "\nPor Favor, seleccione el tipo de usuario \n-------------------------------------\n1- Administrador\n2- Profesor\n3- Estudiante\n0- Para salir\n-------------------------------------" << endl;
  cin >> opcion;
  switch(opcion){
    case 1:
        menuAdmi();
        break;
    case 2:
        menuProf();
        break;
    case 3:
        menuEstu();
        break;
    case 0:
        break;
    default:
        cout << "\nERROR: El valor no es valido\n" << endl;
    }
}
return;
}

int main()
{
    insertarInicioProfesor("Laura", 2021);
    imprimirProfesores();
    insertarAdmin("Paulo", 2021);
    imprimirAdmins();
    insertarEstudiante("Vanessa", 15, 2020);
    insertarEstudiante("Alonso", 18, 2021);
    imprimirEstudiantes();
    //menu();

}
