//Librerias que usaremos
//MysqlClient lo usaremos para manejar la base de datos.
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>

//Funciones
  //Insertar Cliente
    void insertar_nvo_cliente ( char*nombre ){
      //Declaración de Variables
      MYSQL *conexion;
      MYSQL_RES *R;
      MYSQL_ROW COL;
      char *servidor = "localhost";
      char *usuario = "root";
      char *pass = "1234";
      char *base = "casaempenio";

      //Inicialización
      conexion = mysql_init(NULL);
      mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);





      char buffer[500];
      sprintf(buffer,"%s'%s'); ",sentencia,nombre);
      mysql_query(conexion,buffer);
      mysql_close(conexion);
    }
  //Consultar Datos
    void consulta(){
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
      R= mysql_use_result(conexion);
      if(R!=NULL){
        while ((COL = mysql_fetch_row(R)) != NULL){
        printf("%s  %s  \n",COL[0],COL[1]);
        }
      }
      mysql_close(conexion);
    }
int main(){
  //Declarando Variables
  char nombre[100];
  char nombre2[100],nombre3[100],nombre4[100];
  char *ptr,*ptr2,*ptr3,*ptr4;  
  
  consulta();
  puts("Escribe el nombre del nuevo cliente");
  gets(nombre);
  ptr=nombre;
  insertar_nvo_cliente(ptr);
  consulta();
}