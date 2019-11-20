#ifndef persona_h
#define persona_h
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
typedef struct Persona {
    char nombre[50];
    char apellidos[50];
    char direccion[50];
    char correo [50];
    int numerocasa;
    int numerocel;
    int numerotrabajo;

} Persona;

Persona * CrearPersona(char* nombre, char* apellidos, char* direccion, char* correo, int numerocasa, int numerocel, int numerotrabajo){
  Persona * persona = (Persona *) malloc (sizeof(Persona)); 
  strncpy(persona->nombre, nombre, 50);
  strncpy(persona->apellidos, apellidos, 50);
  strncpy(persona->direccion, direccion, 50);
  strncpy(persona->correo, correo, 50);
  persona->numerocasa = numerocasa;
  persona->numerocel = numerocel;
  persona->numerotrabajo = numerotrabajo;

return persona;
}

Persona * CrearPersonaInteractivo(){
  printf("Inserte Nombre(s): \n");
  char Nombre[50];
  fgets(Nombre, sizeof(Nombre),stdin);
  scanf("%50[^\n]", Nombre);
 printf("Inserte Apellidos: \n");
 char Apellidos[50];
 fgets(Apellidos, sizeof(Apellidos),stdin);
 scanf("%50[^\n]", Apellidos);
 printf("Inserte Direccion: \n");
  char Direccion[50];
  fgets(Direccion, sizeof(Direccion), stdin);
  scanf("%50[^\n]", Direccion);
 printf("Inserte Correo\n");
  char Correo[50];
  scanf("%50s", Correo);
  printf("Inserte numero de telefono de casa (8 digitos): \n");
  int Numerocasa;
  scanf("%d",&Numerocasa);
   printf("Inserte numero de celular (8 digitos): \n");
  int Numerocel;
  scanf("%d",&Numerocel);
 printf("Inserte numero de telefono de su trabajo (8 digitos): \n");
  int Numerotrabajo;
  scanf("%d",&Numerotrabajo);

Persona * persona = CrearPersona(Nombre, Apellidos, Direccion, Correo, Numerocasa, Numerocel, Numerotrabajo);

return persona;
}

Persona * LeerPersona (FILE * archivo, Persona * persona){ 
  if (archivo != NULL){
   fscanf(archivo, "%50[^\n]", persona->nombre);
      fgetc(archivo);
   fscanf(archivo, "%50[^\n]", persona->apellidos);
     fgetc(archivo);
   fscanf(archivo, "%50[^\n]", persona->direccion);
     fgetc(archivo);
   fscanf(archivo, "%50[^\n]", persona->correo);
     fgetc(archivo);
   fscanf(archivo, "%d", &persona->numerocasa);
   fscanf(archivo, "%d", &persona->numerocel);
   fscanf(archivo, "%d", &persona->numerotrabajo);
  } else {
     printf("el archivo esta vacio");
  }
  return persona;
} 

void ImprimirPersona(Persona * persona){
printf("Nombre(s): %s\n", persona->nombre);
printf("Apellidos: %s\n", persona->apellidos);
printf("Direccion: %s\n", persona->direccion);
printf("Correo: %s\n", persona->correo);
printf("Numero de casa: %d\n", persona->numerocasa);
printf("Numero de celular: %d\n", persona->numerocel);
printf("Numero de trabajo: %d\n", persona->numerotrabajo);

}

void ModificarPersona (Persona * persona,int campo, void * cambio){
    switch (campo){
      case 1:
  strncpy(persona->nombre,(char *) cambio, 50);
  break;
  case 2: 
  strncpy(persona->apellidos,(char *) cambio, 50);
  break;
  case 3:
  strncpy(persona->direccion,(char *) cambio, 50);
  break;
  case 4:
  strncpy(persona->correo,(char *) cambio, 50);
  break; 
  case 5:
  persona->numerocel =*(int *) cambio;
  break;
  case 6:
  persona->numerocasa =*(int *) cambio;
  break;
  case 7:
  persona->numerotrabajo =*(int *) cambio;
  break;
  
  }
}

void GuardarPersona (Persona * persona, FILE * archivo){
fprintf(archivo,"%s\n", persona->nombre);
fprintf(archivo,"%s\n", persona->apellidos);
fprintf(archivo,"%s\n", persona->direccion);
fprintf(archivo,"%s\n", persona->correo);
fprintf(archivo,"%d\n", persona->numerocasa);
fprintf(archivo,"%d\n", persona->numerocel);
fprintf(archivo,"%d\n", persona->numerotrabajo);
}

#endif

