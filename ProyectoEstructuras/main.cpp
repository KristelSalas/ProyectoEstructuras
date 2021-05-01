#include <iostream>
#include<stdlib.h>
using namespace std;

/*Autores: Anthony Arias y Kristel Salas
Fecha de Inicio: 18-4-2021
Última fecha de modificación: 27-4-2021 */



//Constructores

//Estructura y constructor de lista simple
struct administrador {
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

//Estructura y constructor de lista doble
struct profesor {
    string nombre;
    string apellido;
    int carnetProfesor;
    profesor* sig;
    profesor* ant;
    struct cursosProfes* subListaCursosProfe;

    profesor(string n, string aP, int cP){
        nombre = n;
        apellido = aP;
        carnetProfesor = cP;
        sig = NULL;
        ant = NULL;
        subListaCursosProfe = NULL;
    }
}*primerP;

//Estructura y constructor de lista simple
struct estudiante {
    string nombre;
    int edad;
    int carnetE;
    estudiante*sig;
    struct cursosMatriculados* subListaCursos;

    estudiante(string n, int e, int ce){
        nombre = n;
        edad = e;
        carnetE = ce;
        sig = NULL;
        subListaCursos = NULL;
    }
}*primerE;

//Estructura y constructor de lista circular
struct curso {
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

//Estructura y constructor de sublista simple
struct reunion {
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

//Estructura y constructor de sublista simple
struct cursosMatriculados{
    cursosMatriculados* sig;
    struct curso *enlaceCurso;
    struct asistenciaCursosEstudiante* subListaAsistencia;

    cursosMatriculados(struct curso *c){
        sig = NULL;
        enlaceCurso = c;
        subListaAsistencia = NULL;
    }
};

//Estructura y constructor de sublista simple
struct cursosProfes{
    cursosProfes* sig;
    struct curso *enlaceCursoP;
    struct reunionesCursoProfe* subListaReuniones;

    cursosProfes(struct curso *cu){
        sig = NULL;
        enlaceCursoP = cu;
        subListaReuniones = NULL;
    }
};

//Estructura y constructor de sublista simple
struct reunionesCursoProfe{
    reunionesCursoProfe* sig;
    struct reunion *enlaceCursoReunion;

    reunionesCursoProfe(struct reunion *re){
        sig = NULL;
        enlaceCursoReunion = re;
    }
};

//Estructura y constructor de sublista simple
struct asistenciaCursosEstudiante{
    bool asistencia;
    asistenciaCursosEstudiante* sig;
    struct reunion *enlaceCursoAsistencia;

    asistenciaCursosEstudiante(struct reunion *re, bool asis){
        asistencia = asis;
        sig = NULL;
        enlaceCursoAsistencia = re;
    }

};



//Funciones


// ------------ Admins -------------


administrador* buscarAdmin(int claveA){//función para buscar administradores que recibe por parámetro el carnet único de este y devuelve el objeto
    administrador*temp = primerA;
    while(temp!= NULL){
        if(temp->claveAdmin == claveA)
            return temp;
        temp = temp->sig;
    }
return NULL;// no lo encontro
}

void insertarAdmin(string n, string aP, int cA){ //funcion para insertar administradores que recibe el nombre,apellido y la clave
    administrador *buscarAdminRepetido = buscarAdmin(cA);
    if(buscarAdminRepetido == NULL){
        administrador* nn = new administrador(n, aP, cA);
        nn->sig = primerA;
        primerA = nn;
        cout << "* Administrador insertado con exito *" << endl;
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

void modificarProfesor(int carnetP, string nN, string nA ){//función para modificar la informacion del profesor, recibe el carnet del profesor y los datos nuevos a modificar
    profesor* nodoBuscado= buscarProfe(carnetP);
    if(nodoBuscado == NULL)
        cout<<"** No encontrado, no se puede modificar **";
    else{
        nodoBuscado-> nombre = nN;
        nodoBuscado-> apellido = nA;
    }
}

void eliminarProfe(int carnetP){//funcion para eliminar a un profesor, recibe el carnet de este y lo elimina de la lista
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

void insertarEstudiante(string n, int e, int c){//Funcion para la insercion de los estudiantes recibe el nombre, edad y el carnet
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

void modificarEstudiante(int carnetEstu, string nomN, int edadN){//Funcion para modificar un estudiante, recibe el carnet unico de este para localizarlo y modifica los datos anteriores con los recibidos por parametro
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

void eliminarEstudiante(int carnetEst){ //Funcion para eliminar un estudinate que recibe el carnet para su localizacion
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
    }
}



// ------------ Cursos -------------


curso* buscarCurso(string codCurso){//función para buscar cursos, recibe por parámetro el codigo único de este y devuelve el objeto
if(primerC == NULL)
    return NULL;
curso* temp = primerC;
do{
    if(temp->codigo == codCurso)
        return temp;
    temp = temp->sig;
}while(temp != primerC);
return NULL;// no lo encontro
}

void insertarFinalCurso(string nom, string codC, int cre){//funcion para insertar cursos al final de la lista que recibe el nombre, codigo y numero de creditos de este
    curso* buscarCursoRepetido = buscarCurso(codC);
    if(buscarCursoRepetido == NULL){
        curso* nn = new curso(nom, codC, cre);
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

void modificarCurso(string codC, string nomN, int credN){//funcion para modificar la informacion del curso recibe el codigo del curso a modificar y los datos nuevos como son el nombre y numero de creditos
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

void eliminarCurso(string codCur){ //Funcion para eliminar un curso que recibe el codigo del curso que se desea eliminar y lo elimina de la lista
    curso* cursoEliminar = buscarCurso(codCur);
    if(cursoEliminar == NULL){
        cout <<"Este curso no existe " << endl;
    }
    else if(primerC->codigo == codCur){
        curso* temp = primerC;
        do{
           temp = temp->sig;
        }while(temp->sig != primerC);
        primerC = primerC-> sig;
        temp-> sig = NULL;
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

void insertarReunion(int idR, string fe, string hI, string hF){//funcion de insertar reuniones que recibe el id,fecha,hora de inicio y hora final de la reunion y la crea
    reunion *buscarReunionRepetida = buscarReunion(idR);
    if(buscarReunionRepetida == NULL){
        reunion* nn = new reunion(idR, fe, hI, hF);
        nn->sig = primerR;
        primerR = nn;
    }
    else
        cout << "** Este id de Reunion ya fue utlizado por favor indique otro " << endl;
}


// ------------ Estudiantes y cursos -------------


void insertarCursoEstudiante(int carnetE, string codigoC){ //funcion que le inserta sus cursos a un estudiante, recibe el carnet del estudiante y el codigo del curso que se le desea agregar
    struct estudiante* elEstudiante = buscarEstudiante(carnetE);
    struct curso* elCurso = buscarCurso(codigoC);
    if(elEstudiante == NULL){
        cout<<"*Este estudiante no existe*\n" << endl;
        return;
    }
    if(elCurso == NULL){
        cout<<"*Este curso no existe*\n" << endl;
        return;
    }
    struct cursosMatriculados *nuevaMatricula = new cursosMatriculados(elCurso);
    nuevaMatricula-> sig = elEstudiante-> subListaCursos;
    elEstudiante-> subListaCursos = nuevaMatricula;
    cout<<"* Curso asociado con exito *\n" << endl;
 }

void modificarCursoEstudiante(int carnetE, string codigoCV, string codigoCN){//funcion para modificar un curso por otro, recibe el codigo del curso actual y el codigo del curso al que se quiere cambiar
    estudiante *elEstudiante = buscarEstudiante(carnetE);
    cursosMatriculados* cursoM = elEstudiante-> subListaCursos;
    if (elEstudiante == NULL){
        cout<<"* Estudiante no encontrado *\n" << endl;
    }
    else{
        while(cursoM != NULL){
            if(cursoM->enlaceCurso->codigo == codigoCV){
                curso *cursoNuevo = buscarCurso(codigoCN);
                cursoM->enlaceCurso->codigo = cursoNuevo->codigo;
                cursoM->enlaceCurso->nombre = cursoNuevo->nombre;
                cursoM->enlaceCurso->creditos = cursoNuevo->creditos;
                cout<<"* Curso modificado con exito *\n" << endl;
            }
            cursoM = cursoM-> sig;
        }
    }
}

void eliminarCursoEstudiante(int carnetE, string codigoC){//funcion para eliminar un curso a un estudiante que recibe el carnet del estudiante y el codigo del curso que se desea eliminar
    estudiante *elEstudiante = buscarEstudiante(carnetE);
    cursosMatriculados* cursoM = elEstudiante-> subListaCursos;
    if (elEstudiante == NULL){
        cout<<"* Estudiante no encontrado *\n" << endl;
    }
    else{
        cursosMatriculados *temp = cursoM;
        cursosMatriculados *tempAnt = cursoM;
        while(cursoM != NULL){
            if(cursoM->enlaceCurso->codigo == codigoC){
                tempAnt->sig = temp->sig;
            }
            cursoM = cursoM-> sig;
            tempAnt= temp;
            temp = temp->sig;
        }
    }
}


// ------------ Profesores y cursos -------------


curso* buscarCursoProfe(int carnetP, string codC){//funcion para buscar entre los cursos de un profesor, recibe el carnet del profesor y el id del curso que se desea obtener, devuelve el curso
    profesor *profeBuscar = buscarProfe(carnetP);
    cursosProfes *temp = profeBuscar->subListaCursosProfe;
    while(temp!= NULL){
        if(temp->enlaceCursoP->codigo == codC)
            return temp->enlaceCursoP;
        temp = temp->sig;
    }
return NULL;// no lo encontro
}

void insertarCursoProfesor(int carnetP, string codigoC){//funcion para agregar cursos a un profesor que recibe el carnet del profesor y el codigo del curso que se le desea agregar y realiza la accion
    struct profesor* elProfe = buscarProfe(carnetP);
    struct curso* elCurso = buscarCurso(codigoC);
    if(elCurso == NULL){
        cout<<"Este curso no existe\n" << endl;
        return;
    }
    struct cursosProfes *nuevoCurso = new cursosProfes(elCurso);
    nuevoCurso-> sig = elProfe-> subListaCursosProfe;
    elProfe-> subListaCursosProfe = nuevoCurso;
    cout<<"* Curso asociado con exito *\n" << endl;
 }

 void modificarCursoProfesor(int carnetP, string codigoCV, string codigoCN){//funcion que modifica un curso por otro de un profesor, recibe el carnet del profesor, el codigo del curso viejo y el del nuevo y realiza el cambio
    profesor *elProfesor = buscarProfe(carnetP);
    cursosProfes* cursoNuevo = elProfesor-> subListaCursosProfe;
    if (elProfesor == NULL){
        cout<<"* Profesor no encontrado *\n" << endl;
    }
    else{
        while(cursoNuevo != NULL){
            if(cursoNuevo->enlaceCursoP->codigo == codigoCV){
                curso *nuevo = buscarCurso(codigoCN);
                cursoNuevo->enlaceCursoP->codigo = nuevo->codigo;
                cursoNuevo->enlaceCursoP->nombre = nuevo->nombre;
                cursoNuevo->enlaceCursoP->creditos = nuevo->creditos;
                cout<<"* Curso modificado con exito *\n" << endl;
            }
            cursoNuevo = cursoNuevo-> sig;
        }
    }
}

void eliminarCursoProfesor(int carnetP, string codigoC){//Funcion para eliminar el curso a un profesor que recibe el carnet del profesor y el codigo del curso a eliminar y efectua la accion
    profesor *elProfe = buscarProfe(carnetP);
    cursosProfes* cursoP = elProfe-> subListaCursosProfe;
    if (elProfe == NULL){
        cout<<"* Profesor no encontrado *\n" << endl;
    }
    else{
        cursosProfes *temp = cursoP;
        cursosProfes *tempAnt = cursoP;
        while(cursoP != NULL){
            if(cursoP->enlaceCursoP->codigo == codigoC){
                tempAnt->sig = temp->sig;
            }
            cursoP = cursoP-> sig;
            tempAnt= temp;
            temp = temp->sig;
        }
    }
}


// ------------ Profesores y reuniones -------------


void insertarReunionCursoProfesor(int carnetP, string codCurso, int idReu, string fecha, string horaI, string horaF){ //funcion que le inserta a un curso del profesor una reunion, recibe el carnet del profesor, el codigo del curso y los dato de la reunion como son el id, fecha, hora de inicio y hora de finalizacion
    profesor *elProfesor = buscarProfe(carnetP);
    curso *verificarCurso = buscarCurso(codCurso);
    cursosProfes* elCurso = elProfesor-> subListaCursosProfe;
    if(elCurso == NULL){
        cout << "* Este profesor no tiene cursos asignados *" << endl;
    }
    else if(verificarCurso == NULL){
         cout << "* Este curso no esta asignado al profesor o no existe *";
    }
    else{
        while(elCurso != NULL){
            if(elCurso->enlaceCursoP->codigo == codCurso){
                insertarReunion(idReu,fecha,horaI,horaF);
                reunion *nuevaRe = buscarReunion(idReu);
                struct reunionesCursoProfe *nuevaReunion = new reunionesCursoProfe(nuevaRe);
                nuevaReunion->sig = elProfesor->subListaCursosProfe->subListaReuniones;
                elProfesor->subListaCursosProfe->subListaReuniones = nuevaReunion;
                cout<<"* Reunion insertada con exito *\n" << endl;
            }
            elCurso = elCurso->sig;
        }
    }
}


// ------------ Estudiantes y reuniones -------------


void verificarAsistencia(int carnetEst, string codCurso, int idReu){//funcion que recibe el carnet de estudiante, el codigo del curso y el id de la reunion para verificar la participacion del estudiante en la reunion
    estudiante *elEstudiante = buscarEstudiante(carnetEst);
    curso *verificarCurso = buscarCurso(codCurso);
    reunion *buscarReu = buscarReunion(idReu);
    cursosMatriculados* elCurso = elEstudiante->subListaCursos;
    if(elCurso == NULL){
         cout << "* Este curso no existe *";
    }
    else if(buscarReu == NULL){
        cout << "reunion no encontrada" << endl;
    }
    else if(verificarCurso == NULL){
        cout << " Este curso no existe " << endl;
    }
    else{
        while(elCurso != NULL){
            if(elCurso->enlaceCurso->codigo == codCurso && buscarReu->idReunion == idReu){
                struct asistenciaCursosEstudiante *nuevaAsistencia = new asistenciaCursosEstudiante(buscarReu, true);
                nuevaAsistencia->sig = elEstudiante->subListaCursos->subListaAsistencia;
                elEstudiante->subListaCursos->subListaAsistencia = nuevaAsistencia;
                cout<<"Asistencia verificada con exito al curso " << elCurso->enlaceCurso->nombre <<", fecha " << buscarReu->fecha << endl;
            }
            elCurso = elCurso->sig;
        }
    }
}



// ------------ Imprimir listas y Sublistas -------------


void imprimirEstudiantes(){//funcion para imprimir estudiantes
    estudiante *temp = primerE;
    if (temp == NULL)
        cout << "ERROR: Lista vacia";
    while(temp != NULL){
        cout<<temp-> nombre <<", " << temp-> edad <<", " << temp-> carnetE<< endl;
        temp = temp->sig;
    }
}

void imprimirAdmins(){//funcion para imprimir administradores
    administrador *temp = primerA;
    while(temp != NULL){
        cout<<temp-> nombre <<", " <<temp-> apellido <<", " << temp-> claveAdmin << endl;
        temp = temp->sig;
    }
}

void imprimirProfesores(){//funcion para imprimir profesores
    profesor* temp = primerP;
    while(temp!= NULL){
        cout<<temp-> nombre <<", " <<temp-> apellido <<", " << temp-> carnetProfesor << endl;
        temp = temp->sig;
    }
}

void imprimirCursos(){//funcion para imprimir cursos
    if(primerC == NULL)
        cout << "No hay lista circular" << endl;
    else{
        curso* temp = primerC;
       do{
           cout << temp-> nombre <<", " << temp-> codigo <<", " << temp-> creditos << endl;
           temp = temp->sig;
        }while(temp != primerC);
    }
}

void imprimirReuniones(){//funcion para imprimir reuniones
    reunion *temp = primerR;
    while(temp != NULL){
        cout<<temp->idReunion <<", " << temp->fecha <<", " << temp->horaInicio <<", " << temp->horaFinal << endl;
        temp = temp->sig;
    }
}

void  imprimirCursosEstudiante(int carnetE){//funcion para imprimir los cursos de un estudiante y recibe el carnet de este
    struct estudiante* elEstudiante = buscarEstudiante(carnetE);
    if(elEstudiante == NULL){
        cout<<"Este estudiante no existe" << endl;
        return;
    }
    cout<<"Nombre del Estudiante: " << elEstudiante-> nombre << endl;
    cout<<"Sus cursos son: "<<endl;
    struct cursosMatriculados* tempCursoM = elEstudiante-> subListaCursos;
    while(tempCursoM != NULL){
        cout << tempCursoM->enlaceCurso->nombre << ", " << tempCursoM->enlaceCurso->codigo << ", " << tempCursoM->enlaceCurso->creditos << endl;
        tempCursoM = tempCursoM-> sig;
    }
}

void  imprimirCursosProfe(int carnetP){//funcion para imprimir los cursos de un profesor y recibe el carnet de este
    struct profesor* elProfe = buscarProfe(carnetP);
    if(elProfe == NULL){
        cout<<"Este Profesor no existe" << endl;
        return;
    }
    cout<<"Nombre del Profesor: " << elProfe-> nombre << " " << elProfe-> apellido << endl;
    cout<<"Los cursos que imparte son: "<<endl<<endl;
    struct cursosProfes* tempCursoP = elProfe-> subListaCursosProfe;
    while(tempCursoP != NULL){
        cout <<tempCursoP->enlaceCursoP->nombre << ", " << tempCursoP->enlaceCursoP->codigo << ", " << tempCursoP->enlaceCursoP->creditos << endl;
        tempCursoP = tempCursoP-> sig;
    }
}

void imprimirReunionesCursoProfe(int carnetP){//funcion para imprimir las reuniones de curso de un profesor que recibe el caernete
    struct profesor* elProfe = buscarProfe(carnetP);
    if(elProfe == NULL){
        cout <<"Este Profesor no existe" << endl;
        return;
    }
    cout << "Nombre del Profesor: " << elProfe-> nombre << " " << elProfe-> apellido << endl;
    struct cursosProfes* tempCursoP = elProfe-> subListaCursosProfe;
    cout<<"Tiene las siguientes reuniones: "<< endl << endl;
    while(tempCursoP != NULL){
        if(tempCursoP->subListaReuniones == NULL){
            cout << tempCursoP->enlaceCursoP->nombre <<": No hay reuniones en este curso" << endl;
        }
        else{
            cout << tempCursoP->enlaceCursoP->nombre << ": "<< tempCursoP->subListaReuniones->enlaceCursoReunion->fecha << ", " << tempCursoP->subListaReuniones->enlaceCursoReunion->idReunion << ", " << tempCursoP->subListaReuniones->enlaceCursoReunion->horaInicio << ", " << tempCursoP->subListaReuniones->enlaceCursoReunion->horaFinal << endl;
        }
        tempCursoP = tempCursoP-> sig;
    }
}

void  imprimirAsistenciasEstudiante(int carnetE){//funcion para imprimir las asistencias de un estudiante que recibe el carnet de este y verifica
    struct estudiante* elEstudiante = buscarEstudiante(carnetE);
    if(elEstudiante == NULL){
        cout <<"Este estudiante no existe" << endl;
        return;
    }
    cout << "Nombre del Estudiante: " << elEstudiante-> nombre << endl;
    struct cursosMatriculados* tempAsis = elEstudiante->subListaCursos;
    cout<<"Tiene las siguientes asistencias: "<< endl;
    while(tempAsis != NULL){
        if(tempAsis->subListaAsistencia->asistencia == false){
            cout << tempAsis->subListaAsistencia->enlaceCursoAsistencia->fecha <<": No se asistio a la reunion de ese dia";
        }
        else{
            cout << "El estudiante asistio a la reunion de fecha: " << tempAsis->subListaAsistencia->enlaceCursoAsistencia->fecha;
        }
        tempAsis = tempAsis-> sig;
    }
}



// "FRONTEND"



// Menu para gestionar el crear, modificar y eliminar tanto de estudiantes, como profesores y cursos
void menuGestion(string elemento){

int opcion = -1;
while (opcion != 0){

    if (elemento != "Cursos"){
        cout << "\nGestion de " << elemento << "\n-------------------------------------\n1- Crear " << elemento << " \n2- Modificar " << elemento << " \n3- Eliminar " << elemento<< " \n4- Relacionar " << elemento << "\n0- Para Salir\n-------------------------------------"  << endl;
    }
    else {
        cout << "\nGestion de " << elemento << "\n-------------------------------------\n1- Crear " << elemento << " \n2- Modificar " << elemento << " \n3- Eliminar " << elemento <<  "\n0- Para Salir\n-------------------------------------"  << endl;
    }

    cin >> opcion;
    system("cls");

    switch (opcion){
        //------------------------- CREAR -------------------------
        case 1:
            system("cls");
            //crear estudiante
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
            //crear profesor
            else if (elemento == "Profesores"){
                string nombre;
                string apellido;
                int carnet;

                cout << "Ingrese el nombre de el/la profesor(a)\n-------------------------------------" << endl;
                cin >> nombre;
                system("cls");

                cout << "Ingrese el apellido de el/la profesor(a)\n-------------------------------------" << endl;
                cin >> apellido;
                system("cls");

                cout << "Ingrese el carnet de el/la  profesor(a)\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                insertarInicioProfesor(nombre, apellido, carnet);
            }
            //crear curso
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

                insertarFinalCurso(nombre, codigo, creditos);

            }
            break;
        //------------------------- MODIFICAR -------------------------
        case 2:
            system("cls");
            //modificar estudiante
            if (elemento == "Estudiantes"){
                cout << "Estudiantes\n-------------------------------------" << endl;
                imprimirEstudiantes();
                string nombreN;
                int edadN;
                int carnet;

                cout << "\n\nIngrese el carnet de el/la estudiante\n-------------------------------------" << endl;
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
            //modificar profesor
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
            //modificar curso
            else {
                string nombreN;
                string codigo;
                int creditosN;

                cout << "Ingrese el código del curso\n-------------------------------------" << endl;
                cin >> codigo;
                system("cls");

                cout << "Ingrese el nuevo nombre del curso\n-------------------------------------" << endl;
                cin >> nombreN;
                system("cls");

                cout << "Ingrese la cantidad nueva de creditos del curso\n-------------------------------------" << endl;
                cin >> creditosN;
                system("cls");

                modificarCurso(codigo, nombreN, creditosN);

            }
            break;
        //------------------------- ELIMINAR -------------------------
        case 3:
            system("cls");
            //eliminar estudiante
            if (elemento == "Estudiantes"){
                int carnet;
                cout << "Ingrese el carnet de el/la estudiante\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                eliminarEstudiante(carnet);
            }
            //eliminar profesor
            else if (elemento == "Profesores"){
                int carnet;
                cout << "Ingrese el carnet de el/la  profesor(a)\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                eliminarProfe(carnet);
            }
            //eliminar curso
            else {
                string codigo;
                cout << "Ingrese el codigo del curso a eliminar\n-------------------------------------" << endl;
                cin >> codigo;
                system("cls");

                eliminarCurso(codigo);
            }
            break;
        //------------------------- ASOCIAR -------------------------
        case 4:
            system("cls");
            //asociar estudiante

            if (elemento == "Estudiantes"){
                int carnet;
                cout << "Ingrese el carnet de el/la estudiante a quien desea asociar\n-------------------------------------" << endl;
                cin >> carnet;
                system("cls");

                estudiante* nodoBuscado = buscarEstudiante(carnet);

                if (nodoBuscado != NULL){

                    int opcion3 = -1;
                    while (opcion3 != 0){

                        cout << "1- Para asociar un curso\n2- Para modificar un curso\n3- Para eliminar un curso\n0- para salir\n-------------------------------------" << endl;
                        cin >> opcion3;

                        switch(opcion3){
                            case 1:
                                {
                                system("cls");
                                string cCurso;

                                cout << "Ingrese el codigo del curso que desea asociar a " << nodoBuscado ->nombre <<"\n-------------------------------------" << endl;
                                cin >> cCurso;
                                system("cls");

                                //llamado
                                insertarCursoEstudiante(nodoBuscado ->carnetE, cCurso);
                                break;
                                }
                            case 2:
                                {
                                system("cls");
                                string cCurso2;
                                string cCursoN;
                                cout << "Ingrese el codigo del curso que desea sustituir\n-------------------------------------" << endl;
                                cin >> cCurso2;
                                cout << "\nIngrese el codigo del curso nuevo\n-------------------------------------" << endl;
                                cin >> cCursoN;
                                system("cls");

                                //llamado
                                modificarCursoEstudiante(nodoBuscado ->carnetE, cCurso2, cCursoN);
                                break;
                                }
                            case 3:
                                {
                                system("cls");
                                string cCurso3;

                                cout << "Ingrese el codigo del curso que desea eliminar\n-------------------------------------" << endl;
                                cin >> cCurso3;
                                system("cls");

                                //llamado
                                eliminarCursoEstudiante(nodoBuscado->carnetE,cCurso3);
                                break;
                                }
                            case 0:
                                system("cls");
                                break;
                            default:
                                cout << "\nERROR: El valor no es valido\n" << endl;
                                break;
                        }

                    }

                }
                else {

                    cout << "ERROR: estudiante no existe" << endl;
                }
            }
            //asociar profesor
            else if (elemento == "Profesores"){
                int carnet;
                cout << "Ingrese el carnet de el/la profesor(a) a quien desea asociar\n-------------------------------------" << endl;
                cin >> carnet;

                profesor* nodoBuscado = buscarProfe(carnet);
                system("cls");
                if (nodoBuscado != NULL){

                    int opcion3 = -1;
                    while (opcion3 != 0){

                        cout << "1- Para asociar un curso\n2- Para modificar un curso\n3- Para eliminar un curso\n0- para salir\n-------------------------------------" << endl;
                        cin >> opcion3;

                        switch(opcion3){
                            case 1:
                                {
                                system("cls");
                                string cCurso;

                                cout << "Ingrese el codigo del curso que desea asociar a " << nodoBuscado ->nombre <<"\n-------------------------------------" << endl;
                                cin >> cCurso;
                                system("cls");

                                //llamado
                                insertarCursoProfesor(nodoBuscado ->carnetProfesor, cCurso);
                                break;
                                }
                            case 2:
                                {
                                system("cls");
                                string cCurso2;
                                string cCursoN;

                                cout << "Ingrese el codigo del curso que desea sustituir\n-------------------------------------" << endl;
                                cin >> cCurso2;
                                cout << "\nIngrese el codigo del curso nuevo\n-------------------------------------" << endl;
                                cin >> cCursoN;
                                system("cls");

                                //llamado
                                modificarCursoProfesor(nodoBuscado->carnetProfesor,cCurso2,cCursoN);
                                break;
                                }
                            case 3:
                                {
                                system("cls");
                                string cCurso3;

                                cout << "Ingrese el codigo del curso que desea eliminar\n-------------------------------------" << endl;
                                cin >> cCurso3;
                                system("cls");

                                //llamado
                                eliminarCursoProfesor(nodoBuscado->carnetProfesor,cCurso3);
                                break;
                                }
                            case 0:
                                system("cls");
                                break;
                            default:
                                cout << "\nERROR: El valor no es valido\n" << endl;
                                break;
                        }

                    }

                }
                else {

                  cout << "\nERROR: El profesor no existe\n" << endl;
                }

            }
            //asociar curso *no existe*
            else {
            cout << "\nERROR: El valor no es valido\n" << endl;
            }
            break;
        default:
            cout << "\nERROR: El valor no es valido\n" << endl;
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
    system("cls");

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
            cout << "\nBienvenid@ " << nodoBuscado->nombre << "\n-------------------------------------\n1- Gestionar estudiantes\n2- Gestionar profesores\n3- Gestionar cursos\n4- Agregar otro administrador\n0- Para salir\n-------------------------------------" << endl;
            cin >> opcion;
            switch(opcion){
                case 1:
                    system("cls");
                    menuGestion("Estudiantes");
                    break;
                case 2:
                    system("cls");
                    menuGestion("Profesores");
                    break;
                case 3:
                    system("cls");
                    menuGestion("Cursos");
                    break;
                case 4:
                    {
                    system("cls");
                    cout << "Ingrese el nombre del nuevo admin\n-------------------------------------" << endl;
                    string nAdmin;
                    cin >> nAdmin;
                    system("cls");
                    cout << "Ingrese el apellido del nuevo admin\n-------------------------------------" << endl;
                    string aAdmin;
                    cin >> aAdmin;
                    system("cls");
                    cout << "Ingrese la clave del nuevo admin\n-------------------------------------" << endl;
                    int cAdmin;
                    cin >> cAdmin;
                    system("cls");
                    insertarAdmin(nAdmin, aAdmin, cAdmin);
                    }

                case 0:
                    break;
                default:
                    cout << "\nERROR: El valor no es valido\n" << endl;
                    break;
                }
            }
        break;
        }
    }
    else {
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
            cout << "\nBienvenid@ " << nodoBuscado->nombre << "\n-------------------------------------\n1- Consultar reuniones\n2- Consultar asitencia por reunion\n3- Consultar cuales estudiantes asistieron a todas las reuniones\n4- Consultar estudiantes con mas de 3 ausencias\n5- Consultar reuniones sin asistencia\n6- Crear reunion\n0- Para salir\n-------------------------------------" << endl;
            cin >> opcion;
            system("cls");
            switch(opcion){
                case 1:
                    //consultarReuniones(carnetP);
                    break;
                case 2:
                    //consultarAsistenciaPorReu(carnetP);
                    break;
                case 3:
                    //consultarAsitenciaTodasReu(carnetP);
                    break;
                case 4:
                    //consultarReuSinAsis(carnetP);
                    break;
                case 5:
                    //consultarTresAusencias(carnetP);
                    break;
                case 6:
                    {
                    imprimirCursosProfe(nodoBuscado->carnetProfesor);


                    cout << "Ingrese el codigo del curso al que desea agregar la reunion\n-------------------------------------" << endl;
                    string cCurso;
                    cin >> cCurso;
                    system("cls");

                    cout << "Ingrese el codigo de la reunion\n-------------------------------------" << endl;
                    int cReu;
                    cin >> cReu;
                    system("cls");
                    cout << "Ingrese la fecha en formato dd/mm/aaaa\n-------------------------------------" << endl;
                    string fechaReu;
                    cin >> fechaReu;
                    system("cls");
                    cout << "Ingrese la hora de inicio en formato militar\n-------------------------------------" << endl;
                    string horaI;
                    cin >> horaI;
                    system("cls");
                    cout << "Ingrese la hora de fin en formato militar\n-------------------------------------" << endl;
                    string horaF;
                    cin >> horaF;
                    system("cls");

                    insertarReunionCursoProfesor(nodoBuscado->carnetProfesor, cCurso, cReu,fechaReu,horaI,horaF);
                    break;
                    }
                case 0:
                    break;
                default:
                    cout << "\nERROR: El valor no es valido\n" << endl;
                    break;
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
            cout << "\nBienvenid@ " << nodoBuscado->nombre << "\n-------------------------------------\n1- Consultar reuniones de la semana\n2- Participar en una reunion\n0- Para salir\n-------------------------------------" << endl;
            cin >> opcion;
            switch(opcion){
                case 1:
                    //consultarReunionesSemana();
                    break;
                case 2:{
                    cout << "Ingrese el codigo del curso\n-------------------------------------" << endl;
                    string codCur;
                    cin >> codCur;
                    system("cls");

                    cout << "Ingrese el codigo de la reunion\n-------------------------------------" << endl;
                    int codReu;
                    cin >> codReu;
                    system("cls");

                    verificarAsistencia(nodoBuscado->carnetE, codCur, codReu);
                    break;
                }
                case 0:
                    break;

                default:
                    cout << "\nERROR: El valor no es valido\n" << endl;
                    break;
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

//menu principal donde se selecciona el tipo de usuario con el que se desea ingresar al sistema
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

//Funcion para cargar los datos en el sistema
void cargarDatos(){
    insertarInicioProfesor("Laura", "Mora", 1000);
    insertarInicioProfesor("Oscar", "Zamora", 1001);
    insertarInicioProfesor("Mario", "Arias", 1002);
    insertarInicioProfesor("Natalia", "Campos", 1003);
    insertarInicioProfesor("Veronica", "Araya", 1004);

    insertarAdmin("Paulo", "Vega", 0005);
    insertarAdmin("Jose", "Jimenez", 0001);
    insertarAdmin("Junior", "Alvarado", 0002);
    insertarAdmin("Kristel", "Sanchez", 0003);
    insertarAdmin("Nayiry", "Gomez", 0004);

    insertarEstudiante("Vanessa", 20, 2000);
    insertarEstudiante("Alonso", 18, 2001);
    insertarEstudiante("Alex", 19, 2002);
    insertarEstudiante("Allison", 21, 2003);
    insertarEstudiante("Allan", 22, 2004);

    insertarFinalCurso("Estructuras de Datos", "IC-100", 4);
    insertarFinalCurso("Matematica Discreta", "MA-3030", 4);
    insertarFinalCurso("Fundamentos de Computadores", "IC-1010", 3);
    insertarFinalCurso("Comunicación Oral", "CI-5050", 1);
    insertarFinalCurso("Introduccion a la programacion", "IC-2020",3);

    insertarCursoEstudiante(2000,"IC-100");
    insertarCursoEstudiante(2001,"MA-3030");
    insertarCursoEstudiante(2002,"IC-1010");
    insertarCursoEstudiante(2003,"CI-5050");
    insertarCursoEstudiante(2004,"IC-2020");

    insertarCursoProfesor(1000,"IC-100");
    insertarCursoProfesor(1001,"MA-3030");
    insertarCursoProfesor(1002,"IC-1010");
    insertarCursoProfesor(1003,"CI-5050");
    insertarCursoProfesor(1004,"IC-2020");

    insertarReunionCursoProfesor(1000, "IC-100", 3000, "21/5/2021", "12:00", "16:00");
    insertarReunionCursoProfesor(1001,"MA-3030", 3001, "22/5/2021", "07:00", "11:00");
    insertarReunionCursoProfesor(1002,"IC-1010", 3002, "23/5/2021", "12:00", "16:00");
    insertarReunionCursoProfesor(1003,"CI-5050", 3003, "24/5/2021", "08:00", "12:00");
    insertarReunionCursoProfesor(1004,"IC-2020", 3004, "25/5/2021", "12:00", "15:00");
}

//llamado principal
int main()
{

    cargarDatos();
    menu();

}

