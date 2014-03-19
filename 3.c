            if(val==2){
              system("clear");
              char *nombre , *cliente, *fecha_ini,*fecha_fin;
              float *monto;
              DatosBien datosBien;
              strcpy(cliente,dato.nombre);
              puts("Escribe el nombre del nuevo bien");
              setbuf(stdin,NULL);
              gets(nombre);
              strcpy(datosBien.nombre,nombre);
              puts("Escribe el costo");
              scanf("%f" , &monto);
              datosBien.costo = monto;
              puts("Escribe la fecha de inicio");
              setbuf(stdin,NULL);
              gets(fecha_ini);
              strcpy(datosBien.fecha_inicio,fecha_ini);
              puts("Escribe el vencimiento");
              setbuf(stdin,NULL);
              gets(fecha_fin);
              strcpy(datosBien.fecha_final,fecha_fin);
              insertar_nvo_bien(nombre,cliente,monto,fecha_ini,fecha_fin);
              //agregar_cliente_lista(&Lista, datosBien);
              //imprimir_lista(Lista);
            }