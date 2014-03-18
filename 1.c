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
    /**Crea dinamicamente una Lista de clientes con base en el struct
       La inicializa creando el primer valor como Null**/
    ListaClientes* crearListaClientes( ListaClientes * l1 ){
      l1 = malloc(sizeof(ListaClientes));
      l1 -> headClientes = NULL;
      return l1;
    }
  //Insertar nodo cliente
    /**Aqui se empieza a llenar un nodo del Struct Lista Clientes**/
    void insertar_nodo_clientes(ListaClientes** lista,int llave, DatosCliente informacion){ 
      /**Crearemos variables del tipo struct nodo, y al auxiliar lo
          inicializaremos a semejanza del nodoCLiente**/
      nodoCliente *aux, *iterador;
      aux = malloc(sizeof(nodoCliente));

      if( aux == NULL ){
        return; 
      }
      /**Ahora le asignamos los valores que nos pasaron por referencia desde
        el inicio a nuestra variable auxiliar**/
      aux -> datos = informacion;
      aux -> id = llave;
      aux -> ant = NULL;
      aux -> sig = NULL;
      aux -> headBien = NULL;

      /**Si la el valor de lista headClientes es igual a NULL entonces igualar
        el valor con aux
        Si el valor de headCLientes id es igual a la llave dada, el valor
        siguiente del auxiliar será el actual HeadClientes, y  el valor
        del axiliar actual será igual al headClientes osea el anterior**/
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
  //Consultar Lista de Clientes
    ListaClientes* consulta(){
      MYSQL *conexion;
      MYSQL_RES *R;
      MYSQL_ROW COL;
      char *servidor = "localhost";
      char *usuario = "root";
      char *pass = "1234";
      char *base = "casaempenio";

      conexion = mysql_init(NULL);
      mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
      char sentencia[100]="SELECT * from clientes ;";
      char buffer[512];
      mysql_query(conexion,sentencia);
      R = mysql_use_result(conexion);
      ListaClientes* lista1 = NULL;
      lista1 = crearListaClientes(lista1);
      if(R!=NULL){
        COL = mysql_fetch_row(R);
      while (COL != NULL){
        int id;
        char *ptr,*ptr2;
        DatosCliente info;
        ptr = COL[0];
        ptr2 = COL[1];
        id = atoi(ptr);
        strcpy(info.nombre,ptr2);
        insertar_nodo_clientes(&lista1,id,info);
        COL = mysql_fetch_row(R);
      }
      }else{
        puts("ADVERTENCIA: La base de datos se encuentra vacia"); 
      }
      mysql_close(conexion);
      return lista1;
    }
  //Imprimir la Lista de Clientes
    void imprimir_lista( ListaClientes *lista ){
      nodoCliente *iterador;
      iterador = lista -> headClientes;
      if( iterador == NULL ){
        puts("ADVERTENCIA: La base de datos se encuentra vacia");
      }

      while( iterador!=NULL ){
        printf("%d      ",iterador->id);
        puts((iterador->datos).nombre);
        iterador=iterador->sig;
      }
    }
  //Insertar nuevo cliente
    void insertar_nvo_cliente(char*nombre){
      MYSQL *conexion;
      MYSQL_RES *R;
      MYSQL_ROW COL;
      char *servidor = "localhost";
      char *usuario = "root";
      char *pass = "1234";
      char *base = "casaempenio";

      conexion = mysql_init(NULL);
      mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
      char *sentencia="insert into clientes(nombre) values(";
      char buffer[500];
      sprintf(buffer,"%s'%s'); ",sentencia,nombre);
      mysql_query(conexion,buffer);
      mysql_close(conexion);
    }
int main(){
}