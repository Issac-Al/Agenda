#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "lista.h"

void menu();
void menumodificar();
int main (){
FILE * archivo;
int contador;
int campo;
void * cambio;
Persona * persona;
persona = (Persona *) malloc (sizeof(Persona)); 
do {
  menu();
  archivo = fopen("contactos.txt", "rw+");
  scanf("%d", &contador);
switch (contador){
  case 1:
     system("clear"); 
     persona = CrearPersonaInteractivo();
     GuardarPersona(persona, archivo);
     fclose(archivo);
      printf("Se ha guardado la persona\n");
   break;
  case 2:
     system("clear");
     persona = LeerPersona (archivo, persona);
     fclose(archivo);
     archivo = fopen("contactos.txt", "w");
     printf("¿Que se desea modificar?");
     menumodificar();
     scanf("%d", &campo);
     system("clear");
     printf("Ingrese el nuevo dato: ");
         if (campo < 5){
            system("clear");
            cambio = malloc (50*sizeof(char*));
            fgets(cambio, 50*sizeof(char), stdin);
            scanf("%50[^\n]",(char*) cambio);
    }else{
            system("clear");
            cambio = malloc (sizeof(int));
            scanf("%d",(int*) cambio);
      }
        ModificarPersona(persona, campo, cambio);
        GuardarPersona(persona, archivo);
        fclose(archivo);
        printf("Se ha guardado el cambio\n");
   break;
  case 3:
      system("clear");
     persona = LeerPersona(archivo, persona);
      fclose(archivo);
}
}while(contador != 5);
return 0;
}

void menu(){
  printf("\t\t\t\t\t\t\tTu Agenda\n");
  printf("1.- Para agregar una persona\n");
  printf("2.- Para modificar una persona\n");
  printf("3.- Para borrar una persona\n");
  printf("4.- Para buscar una persona\n");
  printf("5.- Para salir\n");

}

void menumodificar(){
  printf("\n1.- Para modificar nombre(s)\n");
  printf("2.- Para modificar apellidos\n");
  printf("3.- Para modificar direccion\n");
  printf("4.- Para modificar correo\n");
  printf("5.- Para modificar numerocasa\n");
  printf("6.- Para modificar numerocel\n");
  printf("7.- Para modificar numerotrabajo\n");
}
