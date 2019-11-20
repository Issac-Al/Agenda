#ifndef LISTA_H
#define LISTA_H
#include "stdlib.h"
#include "string.h"
#include "persona.h"
typedef struct Nodo{
  Persona persona;
  struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
  Nodo* cabeza; 
  int longitud;
} Lista;

Nodo * CrearNodo(Persona* persona){
  Nodo* nodo = (Nodo *) malloc(sizeof (Nodo));
  strncpy(nodo->persona.nombre, persona->nombre, 50);
  strncpy(nodo->persona.apellidos, persona->apellidos, 50);
  strncpy(nodo->persona.direccion, persona->direccion, 50);
  strncpy(nodo->persona.correo, persona->correo, 50);
  nodo->persona.numerocasa = persona->numerocasa;
  nodo->persona.numerocel = persona->numerocel;
  nodo->persona.numerotrabajo = persona->numerotrabajo;
  nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo) {
  free(nodo);
}

void InsertarPrincipio(Lista* lista, Persona* persona){
  Nodo* nodo = CrearNodo(persona);
  nodo->siguiente = lista->cabeza;
  lista->cabeza = nodo;
  lista->longitud++;
}

void InsertarFinal (Lista* lista, Persona* persona){
  Nodo* nodo = CrearNodo(persona);
  if (lista->cabeza == NULL) {

    lista->cabeza = nodo;
  } else {
   Nodo* puntero = lista->cabeza;
   while (puntero->siguiente) {
      puntero = puntero->siguiente;
   }
   puntero->siguiente = nodo;
  }
  lista->longitud++;
} 

int Contar(Lista* lista){
  return lista->longitud;
} 

void EliminarElemento(int n, Lista* lista) {
  if (lista->cabeza){
      if(n==0){
      Nodo* eliminado = lista->cabeza;
      lista->cabeza = lista->cabeza->siguiente;
      DestruirNodo(eliminado);
      lista->longitud--;
      }else if (n < lista->longitud) {
     Nodo* puntero = lista->cabeza;
     int posicion = 0;
     while (posicion < (n-1)) {
        puntero = puntero->siguiente;
        posicion++;
     }
     Nodo* eliminado = puntero->siguiente;
     puntero->siguiente = eliminado->siguiente;
     DestruirNodo(eliminado);
     lista->longitud--;
     printf("Se ha eliminado el contacto");
      }
   }
}
#endif
