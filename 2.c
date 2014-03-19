//Librerias que usaremos
//MysqlClient lo usaremos para manejar la base de datos.
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>

//Estructuras a usar
  typedef struct{
    char nombre[100];
  }DatosCliente;

  typedef struct{
    char nombre[100];
    float costo;
  }DatosBien;

  typedef struct nodoBien{
    DatosBien datos; 
    int ID;
  }nodoBien;

  typedef struct nodo{
    int id;
    DatosCliente datos;
    struct nodo *sig;
    struct nodo *ant;
    nodoBien *headBien; 
  }nodoCliente;

  typedef struct{
    nodoCliente *headClientes; 
  }ListaClientes;

    void eliminar_nodo_clientes(ListaClientes** l1, DatosCliente info){ 
      nodoCliente *iterador , *aux;
      while(iterador -> sig != NULL ){
        if (iterador->datos.nombre == info.nombre){
          aux = (*iterador)->sig;
          (*iterador)->ant->sig = aux;
          aux->ant = (*iterador)->ant;
          free(*iterador);
          (*iterador) = aux; 
        }
        else{
          iterador = iterador->sig;
        }
      }
    }
