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
      /**Mientras el iterador no tenga el valor Nulo, pediremos el id y nombre**/
      while( iterador != NULL ){
        printf("%d      ",iterador->id);
        puts((iterador->datos).nombre);
        iterador = iterador -> sig;
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
  //Eliminar un cliente
    void eliminar_cliente(char*nombre){
      MYSQL *conexion;
      MYSQL_RES *R;
      MYSQL_ROW COL;
      char *servidor = "localhost";
      char *usuario = "root";
      char *pass = "1234";
      char *base = "casaempenio";
      conexion = mysql_init(NULL);
      mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
      char *sentencia="DELETE FROM clientes where nombre=";
      char buffer[500];
      sprintf(buffer,"%s'%s'; ",sentencia,nombre);
      mysql_query(conexion,buffer);
      mysql_close(conexion);
    }
  //Modificar un cliente
    void modificar_cliente(char*nombre, char*nombre2){
      MYSQL *conexion;
      MYSQL_RES *R;
      MYSQL_ROW COL;
      char *servidor = "localhost";
      char *usuario = "root";
      char *pass = "1234";
      char *base = "casaempenio";
      conexion = mysql_init(NULL);
      mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
      char *sentencia = "update clientes set nombre=";
      char *sentencia2 = "WHERE nombre=";
      char buffer[500];
      sprintf(buffer,"%s '%s' %s '%s';",sentencia,nombre,sentencia2,nombre2);
      mysql_query(conexion,buffer);
      mysql_close(conexion);
    }
  //Agregar cliente a Lista de Clientes
    void agregar_cliente_lista(ListaClientes **l1, DatosCliente info_nueva){
      MYSQL *conexion;
      MYSQL_RES *R;
      MYSQL_ROW COL;
      char *servidor = "localhost";
      char *usuario = "root";
      char *pass = "1234";
      char *base = "casaempenio";
      conexion = mysql_init(NULL);
      mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
      char *sentencia="SELECT * from clientes where nombre=";
      char buffer[500];
      sprintf(buffer,"%s '%s' ;",sentencia,(info_nueva.nombre));
      mysql_query(conexion,buffer);
      R= mysql_use_result(conexion);
      if(R!=NULL){
        COL = mysql_fetch_row(R);
        while (COL != NULL){
          int id;
          char *ptr,*ptr2;
          DatosCliente info;
          ptr=COL[0];
          ptr2=COL[1];
          id=atoi(ptr);
          strcpy(info.nombre,ptr2);
          insertar_nodo_clientes(l1,id,info);
          COL = mysql_fetch_row(R);
        }
      }else{
        puts("El dato solicitado no se pudo ingresar en la base de datos"); 
      }
      mysql_close(conexion);
    }
  //Buscar a un cliente en la Lista de Clientes
    int buscar_en_lista(ListaClientes **l1, char* nombre){
      nodoCliente* iterador=(*l1)->headClientes;  
      int i=0;
      while(iterador!=NULL){
        if(strcmp((iterador->datos.nombre),nombre)==0){
          i=1;
          break;
        }
        iterador=iterador->sig;
      }
      return i;
    }
  //Eliminar un nodo del cliente
    void eliminar_nodo_clientes(ListaClientes** l1, int *llave, char *data){ 
      printf("%s %s\n", "Usuario: ", data);
      printf("%s %d\n", "ID: ", llave);
      printf("%s\n", "Fue eliminado con Exito.");
    }
  //Modificar un registro en la Lista de Clientes
    void modificar_en_lista(ListaClientes **l1, DatosCliente info){
      nodoCliente* iterador=(*l1)->headClientes;
      while(iterador!=NULL){
        if(strcmp((iterador->datos.nombre),(info.nombre))==0){
          break;
        }
        iterador=iterador->sig;
      }
      if(iterador!=NULL){
        char *nvo_nombre;
        puts("Escribe el nuevo nombre");
        setbuf(stdin,NULL);
        gets(nvo_nombre);
        while(strcmp(nvo_nombre,"")==0){
          puts("Escriba un nombre valido");
          setbuf(stdin,NULL);
          gets(nvo_nombre);   
        }
        if(buscar_en_lista(l1,nvo_nombre)==0){
          modificar_cliente(nvo_nombre, iterador->datos.nombre);
          strcpy(iterador->datos.nombre,nvo_nombre);
        }else{
          puts("El cliente ya existe");
        }
      }else{
        puts("El cliente no existe"); 
      }
    }
  void insertar_bien(nodoCliente** cliente, int llave,DatosBien info){
  nodoBien *aux, *iterador;
  aux=malloc(sizeof(nodoBien));
  if(aux==NULL){
    return; 
  }
  aux->datos=info;
  aux->ID=llave;
  aux->sig=NULL;

  if((*cliente)->headBien==NULL){
    (*cliente)->headBien=aux;
    
    
    return; 
  }
  if((*cliente)->headBien->ID==llave){
    aux->sig=(*cliente)->headBien;
    (*cliente)->headBien=aux;
    return; 
  }

  iterador=(*cliente)->headBien;

  while(iterador->sig!=NULL){
    iterador=iterador->sig;   

  }
  
  iterador->sig=aux;
  
  return;

}
//Main
  int main(){
    int val;
    ListaClientes *Lista;
    Lista=consulta();
    system("clear");
    do{
      puts("Bienvenido al Sistema de Bienes. ¿Que desea realizar? ");
      puts("Escriba 1 para Mostrar la lista de los clientes.");
      puts("Escriba 2 para Dar de alta un cliente.");
      puts("Escriba 3 para Dar de baja un cliente.");
      puts("Escriba 4 para Modificar datos un cliente");    
      puts("Escriba 5 para Ver los bienes de un cliente.");
      puts("Escriba 6 para salir.");
      scanf("%d",&val);
      if(val==1){
        system("clear");
        imprimir_lista(Lista);
      }
      if(val==2){
        system("clear");
        char *ptr;
        char nombre1[100];
        DatosCliente dato_nuevo;  
        puts("Escribe el nombre del nuevo cliente");
        setbuf(stdin,NULL);
        gets(nombre1);
        strcpy(dato_nuevo.nombre,nombre1);
        ptr=dato_nuevo.nombre;
        insertar_nvo_cliente(ptr);
        agregar_cliente_lista(&Lista, dato_nuevo);
        imprimir_lista(Lista);
      }
      if(val==3){
        char *data;
        char nombre[100];
        int *llave;
        DatosCliente dato;
        puts("Escribe el cliente a Eliminar");
        setbuf(stdin,NULL);
        gets(nombre);
        strcpy(dato.nombre,nombre);
        data = dato.nombre;
        eliminar_cliente(data);
        puts("Escribe el ID a Eliminar");
        scanf("%d" , &llave);
        eliminar_nodo_clientes(&Lista,llave,data);
        imprimir_lista(Lista);
      }
      if(val==4){
        system("clear");
        DatosCliente dato;
        puts("Escribe el nombre a modificar");
        setbuf(stdin,NULL);
        gets(dato.nombre);
        modificar_en_lista(&Lista,dato);
        imprimir_lista(Lista);
        
      }
      if(val==5){
        system("clear");
        DatosCliente dato;
        int net;
        puts("Escribe el nombre del cliente");
        setbuf(stdin,NULL);
        gets(dato.nombre);
        puts("Escribe tu NETKEY");
        scanf("%d", &net);
        if(buscar_en_lista(&Lista,dato.nombre)==1){
          int val2;
          system("clear");
          do{
            printf("Bienvenido al submenu de bienes del cliente ");
            puts(dato.nombre);
            puts("Escriba 1 para Ver bienes del cliente.");
            puts("Escriba 2 para Ingresar nuevo bien.");
            puts("Escriba 3 para Modificar un bien.");
            puts("Escriba 4 para Eliminar bien.");    
            puts("Escriba 5 para regresar al menu principal.");
            setbuf(stdin,NULL);
            scanf("%d",&val2);
          }while(val2!=5);
          
        }else{
          puts("El cliente no existe");
        }
      }
    }while(val!=6);
  }