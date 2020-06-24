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
    int id,cantidad;
    float precio;
    char codigo[20];
    char fecha[20];
    char cuit[15];

    FILE* f = NULL;
    eVentas* venta;

    if( path != NULL && pVentas != NULL )
    {
        tam = ll_len(pVentas);
        f = fopen(path, "w");

        if( f != NULL )
        {
            fprintf(f, "id,fecha,codigo producto,cantidad,precio unitario,cuit\n");

            for(int i=0; i<tam; i++)
            {
                venta = (eVentas*) ll_get(pVentas, i);
                eVenta_getId(venta, &id);
                eVenta_getFechaVenta(venta, fecha);
                eVenta_getCodigoProducto(venta, codigo);
                eVenta_getCantidad(venta,&cantidad);
                eVenta_getPrecio(venta,&precio);
                //descDias(auxDia,&dia);
                eVenta_getCuit(venta,cuit);
                fprintf(f,"%d,%s,%s,%d,%f,%s\n",id,fecha,codigo,cantidad,precio,cuit);
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
