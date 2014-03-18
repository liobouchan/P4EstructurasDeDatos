//Librerias que usaremos
#include <stdio.h>
#include <stdlib.h>
//MysqlClient lo usaremos para manejar la base de datos.
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
      char *pass = "";
      char *base = "casaempenio";

      //Inicialización
      conexion = mysql_init(NULL);
      mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
      char *sentencia="insert into clientes(nombre) values(";
      char buffer[500];
      sprintf(buffer,"%s'%s'); ",sentencia,nombre);
      mysql_query(conexion,buffer);
      mysql_close(conexion);
    }

int main(){
printf("%s\n", "Hola Mundo" );
}