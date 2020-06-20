#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "eVentas.h"
#include "parser.h"
#include "validaciones.h"

int saveAsText(char* path , LinkedList* pVentas)
{
    int todoOk = 0;
    int tam = 0;
    int contador = 0;
    int id,sala,cantEntradas,dia;
    float monto;
    char nombre[20];
    char horario[20];

    FILE* f = NULL;
    eVentas* venta;

    if( path != NULL && pVentas != NULL )
    {
        tam = ll_len(pVentas);
        f = fopen(path, "w");

        if( f != NULL )
        {
            fprintf(f, "id,nombre,dia,horario,sala,cantEntradas,monto\n");
            char auxDia[10];

            for(int i=0; i<tam; i++)
            {
                venta = (eVentas*) ll_get(pVentas, i);
                eVenta_getId(venta, &id);
                eVenta_getPelicula(venta, nombre);
                eVenta_getDia(venta, &dia);
                eVenta_getHorario(venta,horario);
                eVenta_getSala(venta,&sala);
                eVenta_getCantEntradas(venta,&cantEntradas);
                eVenta_getPrecio(venta,&monto);
                descDias(auxDia,&dia);
                fprintf(f, "%d,%s,%s,%s,%d,%d,%f\n", id, nombre, auxDia, horario, sala, cantEntradas,monto);
                contador++;
            }


            fclose(f);

            if( contador == tam )
            {
                todoOk = 1;

            }

        }
        else
        {
            printf("No se pudo abrir el archivo de texto.\n");
        }
    }

    return todoOk;
}



/*int saveAsBinary(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    int i;
    int len= ll_len(pArrayList);
    eCachorro* this;
    if(path != NULL && pArrayList!= NULL){
       if(fopen(path,"rb")!=NULL){
             f=fopen(path,"wb");
        }else{
            f=fopen(path,"wb");
        }
        if(f!=NULL){
                for(i=0;i<len;i++){
                    this=ll_get(pArrayList,i);
                    if(this!= NULL)
                        fwrite(this,sizeof(eCachorro),1,f);
                        }
                if(i==len){
                    todoOk=1;
                    fclose(f);
                }else{
                    todoOk=0;
                }
            }
    }

    return todoOk;
}
*/
