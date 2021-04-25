#include <iostream>
#include<stdlib.h>
using namespace std;

//Autores: Anthony Arias y Kristel Salas
//Fecha de Inicio: 18-4-2021
//Última fecha de modificación: 23-4-2021


//Constructores

struct administrador { //lista simple
    string nombre;
    string apellido;
    int claveAdmin;
    administrador*sig;

    administrador(string n, string aP, int cA){
        nombre = n;
        apellido = aP;
        claveAdmin = cA;
        sig = NULL;
    }
}*primerA;

struct profesor { //Lista doble con inserción al inicio
    string nombre;
    string apellido;
    int carnetProfesor;
    profesor* sig;
    profesor* ant;

    profesor(string n, string aP, int cP){
        nombre = n;
        apellido = aP;
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
}*primerC;

struct reunion { //lista simple
    int idReunion;
    string fecha;
    string horaInicio;
    string horaFinal;
    reunion*sig;

    reunion(int idR, string fe, string horaIn, string horaFi){
        idReunion = idR;
        fecha = fe;
        horaInicio = horaIn;
        horaFinal = horaFi;
        sig = NULL;
    }
}*primerR;


//Funciones

// ------------ Admins -------------


administrador* buscarAdmin(int claveA){//función para buscar admins que recibe por parámetro el carnet único de este y devuelve el objeto
    administrador*temp = primerA;
    while(temp!= NULL){
        if(temp->claveAdmin == claveA)
            return temp;
        temp = temp->sig;
    }
return NULL;// no lo encontro
}

void insertarAdmin(string n, string aP, int cA){
    administrador *buscarAdminRepetido = buscarAdmin(cA);
    if(buscarAdminRepetido == NULL){
        administrador* nn = new administrador(n, aP, cA);
        nn->sig = primerA;
        primerA = nn;
    }
    else
        cout << "** Esta clave de Administrador ya existe con el nombre de: " << buscarAdminRepetido-> nombre << " **" << endl;
}




// ------------ Profes -------------


profesor* buscarProfe(int carnetP){//función para buscar profesor que recibe por parámetro el carnet único de este y devuelve el objeto
    profesor*temp = primerP;
    while(temp!= NULL){
        if(temp->carnetProfesor == carnetP)
            return temp;
        temp = temp->sig;
    }
return NULL;// no lo encontro
}

void insertarInicioProfesor(string n, string aP, int cP){//funcion para insertar profesores a la lista al inicio, recibe toda la info y crea el nodo
    profesor* buscarProfeRepetido = buscarProfe(cP);
    if(buscarProfeRepetido == NULL){
        profesor* nn = new profesor(n, aP,cP);
        nn->sig = primerP;
        if(primerP != NULL)
            primerP->ant = nn;
        primerP = nn;
        cout << "** Profesor creado con exito **" << endl;
    }
    else
        cout << "** Este Carnet de profesor ya existe con el nombre de: " << buscarProfeRepetido-> nombre << " **" << endl;

}

void modificarProfesor(int carnetP, string nN, string nA ){//función para modificar la info del profesor, recibe el carnet del profesor y los datos nuevos a modificar
    profesor* nodoBuscado= buscarProfe(carnetP);
    if(nodoBuscado == NULL)
        cout<<"** No encontrado, no se puede modificar **";
    else
        nodoBuscado-> nombre = nN;
        nodoBuscado-> apellido = nA;
}

void eliminarProfe(int carnetP){
    profesor* profeBorrar= buscarProfe(carnetP);
    if(profeBorrar == NULL){
        cout<<"** No se encontro el profesor **" << endl;
    }
    else{
        profesor* nodoAnterior = profeBorrar-> ant;
        profesor* nodoSiguiente = profeBorrar-> sig;
        if((profeBorrar->ant== NULL) && (profeBorrar->sig==NULL)){
                primerP = NULL;
                cout<<"** Se elimino el profesor y la lista ha quedado vacia **" << endl;
        }
        else if(profeBorrar == primerP){
            primerP = primerP-> sig;
            primerP-> ant = NULL;
            cout<<"** Se elimino el profesor de la lista" << endl;
        }
        else{
            nodoAnterior->sig = nodoSiguiente;
            if(nodoSiguiente!=NULL)
                nodoSiguiente->ant = nodoAnterior;
            cout<<"** Se elimino el profesor de la lista **" << endl;
        }
    }
}



// ------------ Estudiantes -------------

estudiante* buscarEstudiante(int carnetEst){//función para buscar estudiantes, recibe por parámetro el carnet único de este y devuelve el objeto
    estudiante* temp = primerE;
    while(temp!= NULL){
        if(temp-> carnetE == carnetEst)
            return temp;
        temp = temp->sig;
    }
return NULL;// no lo encontro
}

void insertarEstudiante(string n, int e, int c){//Inserta los estudiantes segun su edad de manera ascendente en el inicio
    estudiante* buscarEstudianteRepetido = buscarEstudiante(c);
    if(buscarEstudianteRepetido == NULL){
        estudiante*nn = new estudiante(n, e, c);
        nn->sig = primerE;
        primerE = nn;
        cout << "** Estudiante creado con exito **" << endl;
    }
    else
        cout << "** Este carnet ya existe **" << endl;
}

void modificarEstudiante(int carnetEstu, string nomN, int edadN){
    estudiante * estudianteCambiar = buscarEstudiante(carnetEstu);
    if (estudianteCambiar == NULL){
        cout<<"** Estudiante no encontrado **" << endl;
    }
    else{
        estudianteCambiar->nombre = nomN;
        estudianteCambiar->edad = edadN;
        cout<<"** Estudiante Modificado con exito **" << endl;
    }
}

void eliminarEstudiante(int carnetEst){ //MODIFICAR ESTE METODO CON EL BUSCAR ESTUDIANTE
    if(primerE == NULL){
        cout <<"ERROR: Lista vacia" << endl;
    }
    else if(primerE->carnetE == carnetEst){
        primerE = primerE->sig;
    }
    else{
        estudiante *temp = primerE;
        estudiante *tempAnt= primerE;
        while(temp != NULL){
            if(temp->carnetE == carnetEst){//borrar
                tempAnt->sig = temp->sig;
            }
            tempAnt= temp;
            temp = temp->sig;
        }
        if(temp==NULL){
            cout<<"ERROR: Este estudiante no existe" << endl;
        }
    }
}


// ------------ Cursos -------------

curso* buscarCurso(string codCurso){//función para buscar cursos, recibe por parámetro el codigo único de este y devuelve el objeto
    curso* temp = primerC;
    do{
        if(temp-> codigo == codCurso)
            return temp;
        temp = temp->sig;
    }while(temp != primerC);
    return NULL;// no lo encontro
}

void insertarFinalCurso(string nom, string cod,int cre){
    curso *buscarCursoRepetido = buscarCurso(cod);
    if(buscarCursoRepetido == NULL){
        curso* nn = new curso(nom, cod, cre);
        if(primerC == NULL){
            primerC = nn;
            nn->sig = nn;
        }
        else{
            nn->sig = primerC;
            curso* temp = primerC;
            while(temp->sig != primerC)
                temp = temp->sig;
            temp->sig = nn;
        }
    }
    else
        cout << "** Este Curso ya existe con el nombre de: " << buscarCursoRepetido-> nombre << " **" << endl;

}

void modificarCurso(string codC, string nomN, int credN){
    curso * cursoCambiar = buscarCurso(codC);
    if (cursoCambiar == NULL){
        cout<<"** Curso no encontrado **" << endl;
    }
    else{
        cursoCambiar-> nombre = nomN;
        cursoCambiar-> creditos = credN;
        cout<<"** Curso Modificado con exito **" << endl;
    }
}

void eliminarCurso(string codCur){
    curso* cursoEliminar = buscarCurso(codCur);
    if(cursoEliminar == NULL){
        cout <<"Este curso no existe " << endl;
    }
    else if(primerC-> codigo == codCur){
        primerC = primerC-> sig;
    }
    else{
        curso* temp = primerC;
        curso* tempAnt= primerC;
        do{
           if(temp-> codigo == codCur)
                tempAnt->sig = temp->sig;
           tempAnt= temp;
           temp = temp->sig;
        }while(temp != primerC);
    }
}


// ------------ Reuniones -------------


reunion* buscarReunion(int idRe){//función para buscar reuniones que recibe por parámetro el códigp único de esta y devuelve el objeto
    reunion*temp = primerR;
    while(temp!= NULL){
        if(temp-> idReunion == idRe)
            return temp;
        temp = temp->sig;
    }
return NULL;// no lo encontro
}

void insertarReunion(int idR, string fe, string hI, string hF){
    reunion *buscarReunionRepetida = buscarReunion(idR);
    if(buscarReunionRepetida == NULL){
        reunion* nn = new reunion(idR, fe, hI, hF);
        nn->sig = primerR;
        primerR = nn;
    }
    else
        cout << "** Este id de Reunion ya fue utlizado por favor indique otro " << endl;
}


// ------------ Imprimirsh que luego se borran xd -------------


void imprimirEstudiantes(){//para imprimir estudiantes se borra luego xd
    estudiante *temp = primerE;
    if (temp == NULL)
        cout << "ERROR: Lista vacia";
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

void imprimirProfesores(){//esto es nomas para probar luego se puede borrar
    profesor* temp = primerP;
    while(temp!= NULL){
        cout<<temp->nombre <<", " << temp->carnetProfesor << endl;
        temp = temp->sig;
    }
}

void imprimirCursos(){//esto es nomas para probar luego se puede borrar
    if(primerC == NULL)
        cout<<"\nNo hay lista circular";
    else{
        curso* temp = primerC;
       do{
            cout << temp-> nombre <<", " << temp-> codigo <<", " << temp-> creditos << endl;
            temp = temp->sig;
        }while(temp != primerC);
    }
}


void imprimirReuniones(){//para imprimir admins se borra luego xd
    reunion *temp = primerR;
    while(temp != NULL){
        cout<<temp->idReunion <<", " << temp->fecha <<", " << temp->horaInicio <<", " << temp->horaFinal << endl;
        temp = temp->sig;
    }
}

// "frontend"

// Menu para gestionar el crear, modificar y eliminar tanto de estudiantes, como profesores y cursos ** SIN TERMINAR **
void menuGestion(string elemento){
system("cls");
int opcion = -1;
while (opcion != 0){

    cout << "\nGestion de " << elemento << "\n-------------------------------------\n1- Crear " << elemento << " \n2- Modificar " << elemento << " \n3- Eliminar " << elemento << "\n0- Para Salir\n-------------------------------------"  << endl;
    cin >> opcion;

    switch (opcion){
        //------------------------- CREAR -------------------------
        case 1:
            system("cls");
            if (elemento == "Estudiantes"){
                string nombre;
                int edad;
                int carnet;
                cout << "Ingrese el nombre de el/la estudiante\n-------------------------------------" << endl;
                cin >> nombre;
                system("cls");
                cout << "Ingrese la edad de el/la estudiante\n-------------------------------------" << endl;
                cin >> edad;
                system("cls");
                cout << "Ingrese el carnet de el/la estudiante\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                insertarEstudiante(nombre, edad, carnet);
            }
            else if (elemento == "Profesores"){
                string nombre;
                string apellido;
                int carnet;
                cout << "Ingrese el nombre de el/la profesor(a)\n-------------------------------------" << endl;
                cin >> nombre;
                system("cls");
;
                cout << "Ingrese el apellido de el/la profesor(a)\n-------------------------------------" << endl;
                cin >> apellido;
                system("cls");

                cout << "Ingrese el carnet de el/la  profesor(a)\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                insertarInicioProfesor(nombre, apellido, carnet);
            }
            else {
                string nombre;
                string codigo;
                int creditos;
                cout << "Ingrese el nombre del curso\n-------------------------------------" << endl;
                cin >> nombre;
                system("cls");
                cout << "Ingrese el codigo del curso\n-------------------------------------" << endl;
                cin >> codigo;
                system("cls");
                cout << "Ingrese la cantidad de creditos del curso\n-------------------------------------" << endl;
                cin >> creditos;
                system("cls");

                //insertarCurso(nombre, codigo, creditos);

            }
            break;
        //------------------------- MODIFICAR -------------------------
        case 2:
            system("cls");
            if (elemento == "Estudiantes"){
                string nombreN;
                int edadN;
                int carnet;
                cout << "Ingrese el carnet de el/la estudiante\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");
                cout << "Ingrese el nombre nuevo de el/la estudiante\n-------------------------------------" << endl;
                cin >> nombreN;
                system("cls");
                cout << "Ingrese la edad nueva de el/la estudiante\n-------------------------------------" << endl;
                cin >> edadN;
                system("cls");

                modificarEstudiante(carnet, nombreN, edadN);
            }
            else if (elemento == "Profesores"){
                string nombreN;
                string apellidoN;
                int carnet;
                cout << "Ingrese el carnet de el/la  profesor(a)\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");
                cout << "Ingrese el nombre nuevo de el/la profesor(a)\n-------------------------------------" << endl;
                cin >> nombreN;
                system("cls");
                cout << "Ingrese el apellido nuevo de el/la profesor(a)\n-------------------------------------" << endl;
                cin >> apellidoN;
                system("cls");

                modificarProfesor(carnet, nombreN, apellidoN);
            }
            else {
                //---------------- ACA VA EL MODIFICAR CURSO
                //string nombre;
                //string codigo;
                //int creditos;
                //cout << "Ingrese el nombre del curso\n-------------------------------------" << endl;
                //cin >> nombre;
                //system("cls");
                //cout << "Ingrese el codigo del curso\n-------------------------------------" << endl;
                //cin >> codigo;
                //system("cls");
                //cout << "Ingrese la cantidad de creditos del curso\n-------------------------------------" << endl;
                //cin >> creditos;
                //system("cls");

                //modificarCurso(nombre, codigo, creditos);;

            }
            break;
        //------------------------- ELIMINAR -------------------------
        case 3:
            system("cls");
            if (elemento == "Estudiantes"){
                int carnet;
                cout << "Ingrese el carnet de el/la estudiante\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                eliminarEstudiante(carnet);
            }
            else if (elemento == "Profesores"){
                int carnet;
                cout << "Ingrese el carnet de el/la  profesor(a)\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                eliminarProfe(carnet);
            }
            else {

                //---------------- ACA VA EL ELIMINAR CURSO
                //string nombre;
                //string codigo;
                //int creditos;
                //cout << "Ingrese el nombre del curso\n-------------------------------------" << endl;
                //cin >> nombre;
                //system("cls");
                //cout << "Ingrese el codigo del curso\n-------------------------------------" << endl;
                //cin >> codigo;
                //system("cls");
                //cout << "Ingrese la cantidad de creditos del curso\n-------------------------------------" << endl;
                //cin >> creditos;
                //system("cls");

                //modificarCurso(nombre, codigo, creditos);

            }
            break;


    }
}
return;
}

//menu que se muestra cuando se ingresa como usuario de tipo administrador
void menuAdmi(){
 system("cls");
int claveAd;
bool validacion = false;
while (validacion != true){
    cout << "\nPor favor ingrese su clave o digite 0 para volver\n-------------------------------------" << endl;
    cin >> claveAd;

    if (claveAd != 0){
        administrador* nodoBuscado = buscarAdmin(claveAd);
        if(nodoBuscado == NULL){
        system("cls");
        cout<<"\nERROR: El usuario no es valido\n";
        }
        else {
            validacion = true;
            int opcion = -1;
            while (opcion != 0){
            system("cls");
            cout << "\nBienvenid@ " << nodoBuscado->nombre << "\n-------------------------------------\n1- Gestionar estudiantes\n2- Gestionar profesores\n3- Gestionar cursos\n0- Para salir\n-------------------------------------" << endl;
            cin >> opcion;
            switch(opcion){
                case 1:
                    menuGestion("Estudiantes");
                    break;
                case 2:
                    menuGestion("Profesores");
                    break;
                case 3:
                    menuGestion("Cursos");
                    break;
                case 0:
                    break;
                default:
                    cout << "\nERROR: El valor no es valido\n" << endl;
                }
            }
        break;
        }
    }
    else{
        system("cls");
        break;
    }

}

 return;
}

//menu que se muestra cuando se ingresa como usuario de tipo profesor
void menuProf(){

system("cls");
int carnetP;
bool validacion = false;
while (validacion != true){
    cout << "\nPor favor ingrese su identificacion o digite 0 para volver\n-------------------------------------" << endl;
    cin >> carnetP;

    if (carnetP != 0){
        profesor* nodoBuscado = buscarProfe(carnetP);
        if(nodoBuscado == NULL){
        system("cls");
        cout<<"\nERROR: El usuario no es valido\n";
        }
        else {
            validacion = true;
            int opcion = -1;
            while (opcion != 0){
            system("cls");
            cout << "\nBienvenid@ " << nodoBuscado->nombre << "\n-------------------------------------\n1- Consultar reuniones\n2- Consultar asitencia por reunion\n3- Consultar cuales estudiantes asistieron a todas las reuniones\n4- Consultar estudiantes con mas de 3 ausencias\n5- Consultar reuniones sin asistencia\n0- Para salir\n-------------------------------------" << endl;
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
                case 4:
                    //consultarReuSinAsis();
                    break;
                case 5:
                    //consultarTresAusencias();
                    break;
                case 0:
                    break;
                default:
                    cout << "\nERROR: El valor no es valido\n" << endl;
                }
            }
        break;
        }
    }
    else{
        system("cls");
        break;
    }

}
return;
}

//menu que se muestra cuando se ingresa como usuario de tipo estudiante
void menuEstu(){
system("cls");
int carnetE;
bool validacion = false;
while (validacion != true){
    cout << "\nPor favor ingrese su identificacion o digite 0 para volver\n-------------------------------------" << endl;
    cin >> carnetE;

    if (carnetE != 0){
        estudiante* nodoBuscado = buscarEstudiante(carnetE);
        if(nodoBuscado == NULL){
        system("cls");
        cout<<"\nERROR: El usuario no es valido\n";
        }
        else {
            validacion = true;
            int opcion = -1;
            while (opcion != 0){
            system("cls");
            cout << "\nBienvenid@ " << nodoBuscado->nombre << "\n-------------------------------------\n1- Consultar reuniones de la semana\n0- Para salir\n-------------------------------------" << endl;
            cin >> opcion;
            switch(opcion){
                case 1:
                    //consultarReunionesSemana();
                    break;

                case 0:
                    break;
                default:
                    cout << "\nERROR: El valor no es valido\n" << endl;
                }
            }
        break;
        }
    }
    else{
        system("cls");
        break;
    }

}
return;
}


void menu(){
int opcion = -1;
while (opcion != 0){
  system("cls");
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
    //cout << " --- profes --- " << endl;
    insertarInicioProfesor("Laura", "Mora", 2021);
    //insertarInicioProfesor("Oscar", 2021);
    //insertarInicioProfesor("Oscar", 2027);
    //insertarInicioProfesor("Mario", 2309);
    //imprimirProfesores();
    //cout << endl << "Cambiiooosss" << endl;
    //eliminarProfe(2021);
    //imprimirProfesores();


    //cout << endl << " --- Admins --- " << endl;
    insertarAdmin("Paulo", "kk", 2021);
    //imprimirAdmins();

    //La insercion de estudiantes de esta haciendo al inicio pero tiene que ser ordenada por algun parametro y no logro hacerlo help
    //cout << endl << " --- estudiantes --- " << endl;
    insertarEstudiante("Vanessa", 15, 2020);
    //insertarEstudiante("Alonso", 18, 2021);
    //insertarEstudiante("Vanessa", 15, 2020);
    //imprimirEstudiantes();
    //modificarEstudiante(2021, "Pepe", 19);
    //imprimirEstudiantes();

    //cout << endl << "Cambiiooosss" << endl;
    //eliminarEstudiante(2021);
    //imprimirEstudiantes();

    //cout << " --- cursos --- " << endl;

    insertarFinalCurso("Estructuras", "E 2089", 4);
    insertarFinalCurso("Comu Escrita", "CE 2000", 2);
    insertarFinalCurso("Introduccion", "I 1000", 5);
    insertarFinalCurso("Poo", "P 2654", 3);
    //imprimirCursos();

    //cout << endl << "Cambiiooosss" << endl;

    //modificarCurso("CE 2000", "Comu Oral", 3);
    //imprimirCursos();

    //eliminarCurso("I 100");
    //cout << endl << "curso eliminado" << endl;
    //imprimirCursos();


    cout << " --- reuniones --- " << endl;

    insertarReunion(2343, "26/4/2021", "12:00", "4:00");
    insertarReunion(2343, "26/4/2021", "12:00", "4:00");
    insertarReunion(2342, "27/4/2021", "7:00", "11:00");
    insertarReunion(2344, "28/4/2021", "12:00", "4:00");
    imprimirReuniones();

    //menu();

}

