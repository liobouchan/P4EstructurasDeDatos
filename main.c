# include <stdio.h>
# include <stdlib.h>
# include <mysql/mysql.h>
# include <string.h>

void consulta(){
	MYSQL *conexion;
	MYSQL_RES *R;
  	MYSQL_ROW COL;
	char *servidor = "localhost";
	char *usuario = "root";
	char *pass = "";
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

void insertar_nvo_cliente(char*nombre){
	MYSQL *conexion;
	MYSQL_RES *R;
  	MYSQL_ROW COL;
	char *servidor = "localhost";
	char *usuario = "root";
	char *pass = "";
	char *base = "casaempenio";
	conexion = mysql_init(NULL);
  	mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
	char *sentencia="insert into clientes(nombre) values(";
	char buffer[500];
	sprintf(buffer,"%s'%s'); ",sentencia,nombre);
	mysql_query(conexion,buffer);
	mysql_close(conexion);
	
}

void eliminar_cliente(char*nombre){
	MYSQL *conexion;
	MYSQL_RES *R;
  	MYSQL_ROW COL;
	char *servidor = "localhost";
	char *usuario = "root";
	char *pass = "";
	char *base = "casaempenio";
	conexion = mysql_init(NULL);
  	mysql_real_connect(conexion,servidor,usuario,pass,base,0,NULL,0);
	char *sentencia="DELETE FROM clientes where nombre=";
	char buffer[500];
	sprintf(buffer,"%s'%s'; ",sentencia,nombre);
	mysql_query(conexion,buffer);
	mysql_close(conexion);
	
}

void modificar_cliente(char*nombre, char*nombre2){
	MYSQL *conexion;
	MYSQL_RES *R;
  	MYSQL_ROW COL;
	char *servidor = "localhost";
	char *usuario = "root";
	char *pass = "";
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

int main(){
	int val;
	char nombre[100];
	char nombre2[100];
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
			consulta();
		}
		if(val==2){
			char *ptr;	
			puts("Escribe el nombre del nuevo cliente");
			gets(nombre);
			ptr=nombre;
			insertar_nvo_cliente(ptr);
			consulta();
		}
		if(val==3){
		}
		if(val==4){
		}
		if(val==5){
			int id;
			system("clear");
			//Hay que poner la validacion del cliente pero con Listas
			puts("Bienvenido al sub-menu para gestionar los bienes del cliente.");
			puts("¿Que desea hacer?");
		}
	}while(val!=6);
	/*char nombre[100];
	char nombre2[100],nombre3[100],nombre4[100];
	char *ptr,*ptr2,*ptr3,*ptr4;	
	puts("Escribe el nombre del nuevo cliente");
	gets(nombre);
	ptr=nombre;
	insertar_nvo_cliente(ptr);
	consulta();
	puts("Escribe el nombre del cliente a eliminar");
	gets(nombre2);
	ptr2=nombre2;
	eliminar_cliente(ptr2);
	consulta();
	puts("Escribe el nombre a modificar");
	gets(nombre3);
	ptr3=nombre3;
	puts("Escribe el nuevo valor de nombre");
	gets(nombre4);
	ptr4=nombre4;
	modificar_cliente(ptr4,ptr3);
	consulta();*/
	
}




