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
//Funciones
  //Inicializar Lista
    ListaClientes* crearListaClientes( ListaClientes * l1 ){
      l1 = malloc(sizeof(ListaClientes));
      l1 -> headClientes = NULL;
      return l1;
    }
  //Insertar nodo cliente
    void insertar_nodo_clientes(ListaClientes** lista,int llave, DatosCliente informacion){ 
      nodoCliente *aux, *iterador;
      aux = malloc(sizeof(nodoCliente));

      if( aux == NULL ){
        return; 
      }

      aux->datos=informacion;
      aux->id=llave;
      aux->ant=NULL;
      aux->sig=NULL;
      aux->headBien=NULL;

      if( (*lista) -> headClientes == NULL ){
        (*lista) -> headClientes = aux;
        return; 
      }
      if( (*lista) -> headClientes -> id == llave ){
        aux -> sig = (*lista) -> headClientes;
        (*lista) -> headClientes = aux;
        return;
      }

      iterador = (*lista) -> headClientes;

      while( iterador -> sig != NULL ){
        iterador=iterador->sig;
      }

      aux -> ant = iterador;
      iterador -> sig = aux;
      return;
    }
int main(){
}