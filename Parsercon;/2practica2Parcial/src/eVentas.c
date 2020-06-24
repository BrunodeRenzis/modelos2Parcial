#include "eVentas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "utn.h"
#include "LinkedList.h"


void eVentas_delete(eVentas* this)
{
    if(this!=NULL)
    {
        free(this);
    }

}
///////////////////////FUNCION SET Y GET ID
int eVenta_setId(eVentas* this,int id)
{
    int todoOk=0;
    if(this!=NULL && id>0)
    {
        this->id_venta=id;
        todoOk=1;
    }

    return todoOk;
}

int eVenta_getId(eVentas* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id_venta;
        todoOk=1;
    }
    return todoOk;
}
///////////////////////////////////////////////


////////////////////////////////////////////////SET Y GET NOMBRE
int eVenta_setFechaVenta(eVentas* this,char* auxFecha)
{
    int todoOk=0;
    if(this!=NULL && auxFecha!=NULL)
    {
        strcpy(this->fechaVenta,auxFecha);
        todoOk=1;
    }
    return todoOk;
}

int eVenta_getFechaVenta(eVentas* this,char* auxFecha)
{
    int todoOk=0;
    //printf("AuxNom antes: %s",auxNom);
    if(this!=NULL && auxFecha!=NULL)
    {
        strcpy(auxFecha, this->fechaVenta);
        todoOk=1;
    }
    //printf("AuxNom Despues: %s",auxNom);
    return todoOk;
}
//////////////////////////////////////////////////////

////////////////////////////////////////////GET Y SET DIAS
int eVenta_setCodigoProducto(eVentas* this,char* auxCodigo)
{
    int todoOk=0;
    //printf("auxDias %d\n\n\n\n",auxDias);
    if(this!=NULL && auxCodigo>=0)
    {
        //printf("auxDias %d\n",auxDias);
        strcpy(this->codigoProducto,auxCodigo);
        todoOk=1;
    }
    //printf("diasCachorro %d",this->dias);
    return todoOk;
}

int eVenta_getCodigoProducto(eVentas* this,char* auxCodigo)
{
    int todoOk=0;
    if(this!=NULL && auxCodigo!=NULL)
    {
        strcpy(auxCodigo,this->codigoProducto);
        todoOk=1;
    }
    return todoOk;
}

int eVenta_setCuit(eVentas* this,char* auxCuit)
{
    int todoOk=0;

    if(this!=NULL && auxCuit!=NULL)
    {
        strcpy(this->cuit,auxCuit);
        todoOk=1;
    }

    return todoOk;
}

int eVenta_getCuit(eVentas* this,char* auxCuit)
{

    int todoOk=0;
    if(this!=NULL)
    {
        strcpy(auxCuit,this->cuit);
        todoOk=1;
    }
    return todoOk;
}

int eVenta_setCantidad(eVentas* this,int auxCant)
{
    int todoOk=0;
    if(this!=NULL)
    {
        this->cantidad = auxCant;
        todoOk=1;
    }
    return todoOk;
}

int eVenta_getCantidad(eVentas* this,int* auxCant)
{
    int todoOk=0;
    if(this!=NULL && auxCant!=NULL)
    {
    	*auxCant=this->cantidad;
        todoOk=1;
    }
    return todoOk;
}

int eVenta_setPrecio(eVentas* this, float auxPrecio)
{
    int todoOk=0;

    if(this!=NULL)
    {
    	this->precioUnitario=auxPrecio;
        todoOk=1;
    }

    return todoOk;
}

int eVenta_getPrecio(eVentas* this, float* auxprecio)
{
    int todoOk=0;

    if(this!=NULL && auxprecio!=NULL)
    {
    	*auxprecio=this->precioUnitario;
        todoOk=1;
    }

    return todoOk;
}
///////////////////////////////////////////////////////////////



eVentas* eVenta_new()
{
    eVentas* newVenta;
    newVenta = (eVentas*) malloc(sizeof(eVentas));
    if(newVenta != NULL)
    {
        newVenta->id_venta = 0;
        strcpy(newVenta->fechaVenta," ");
        strcpy(newVenta->codigoProducto," ");
        newVenta->cantidad=0;
        newVenta->precioUnitario=0;
        strcpy(newVenta->cuit," ");
    }

    else
    {
        eVentas_delete(newVenta);
        newVenta=NULL;
    }
    return newVenta;

}


eVentas* eVenta_newParametros(char* idStr,char* fechaStr,char* codigoStr,char* cantidadStr,char* precioUnitarioStr, char* cuitStr)
{
    eVentas* newVenta;
    newVenta=eVenta_new();
    if(idStr!=NULL && cantidadStr!=NULL && precioUnitarioStr!=NULL && codigoStr!=NULL &&fechaStr!=NULL && cuitStr!=NULL)
    {
        if(eVenta_setId(newVenta,atoi(idStr))==0||
                eVenta_setCantidad(newVenta,atoi(cantidadStr))==0||
                eVenta_setCodigoProducto(newVenta,codigoStr)==0||
                eVenta_setPrecio(newVenta,atof(precioUnitarioStr))==0||
                eVenta_setFechaVenta(newVenta,fechaStr)==0||
                eVenta_setCuit(newVenta,cuitStr)==0)
        {
            eVentas_delete(newVenta);
            newVenta=NULL;
        }
    }
    return newVenta;
}

int eVenta_isValid(eVentas* pAux)
{
    int todoOk=0,id,cantidad;
    float precio;
    char cuit[10];
    char fecha[50];
    char codigoProd[30];
    if(pAux!=NULL)
    {
        eVenta_getId(pAux,&id);
        eVenta_getFechaVenta(pAux,fecha);
        eVenta_getCodigoProducto(pAux,codigoProd);
        eVenta_getCantidad(pAux,&cantidad);
        eVenta_getPrecio(pAux,&precio);
        eVenta_getCuit(pAux,cuit);

        if(id>=0  && id<1001 && codigoProd !=NULL && cuit!=NULL && fecha !=NULL && precio>=0 && cantidad>=0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}

void showHeaderVentasSinMonto()
{
	printf("ID VENTA       FECHA           CODIGO       CANTIDAD    PRECIO    CUIT CLIENTE\n");
}

void descDias(char* auxDia,int* dia)
{


		switch (*dia)
		{
			case 0:
				strcpy(auxDia,"Domingo");
				break;

			case 1:
				strcpy(auxDia,"Lunes");
				break;

			case 2:
				strcpy(auxDia,"Martes");
				break;

			case 3:
				strcpy(auxDia,"Miercoles");
				break;

			case 4:
				strcpy(auxDia,"Jueves");
				break;

			case 5:
				strcpy(auxDia,"Viernes");
				break;

			case 6:
				strcpy(auxDia,"Sabado");
				break;
		}

}

int printVentas(eVentas* this)
{
    int todoOk=0,id,cantidad;
    char fecha[20], cuit[15],codigo[30];
    float precio;

    if(this!=NULL)
    {
        eVenta_getId(this,&id);
        eVenta_getFechaVenta(this,fecha);
        eVenta_getCodigoProducto(this,codigo);
        eVenta_getCantidad(this,&cantidad);
        eVenta_getPrecio(this,&precio);
        eVenta_getCuit(this,cuit);
        //descDias(descDia,&codigo);
        printf("%5d %20s %10s %12d %11.2f %20s\n",id,fecha,codigo,cantidad,precio,cuit);
        todoOk=1;
    }

    return todoOk;
}


/*void* eVenta_llmap(void* pAux)
{

    if(pAux!= NULL)
    {
    	float monto;
        eVentas* pelicula=(eVentas*)pAux;
        int diaPelicula,cantEntradas,total;
        eVenta_getCodigoProducto(pelicula,&diaPelicula);
        eVenta_getCantEntradas(pelicula,&cantEntradas);

        if(diaPelicula>=1 && diaPelicula<=3)
        {
        	monto=240;
        }

        else
        {
        	monto=350;
        }
        if(cantEntradas>3)
        {
        	monto=(monto*0.9);
        }

        total = monto*cantEntradas;
        eVenta_setPrecio(pelicula,total);
    }
    return pAux;
}
*/

