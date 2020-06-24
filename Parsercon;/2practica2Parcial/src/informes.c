#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "eVentas.h"
#include "parser.h"
#include "validaciones.h"
#include "informes.h"
#include "Save.h"
#include "utn.h"

void menuInformes(LinkedList* this)
{

	printf("Cantidad de unidades totales vendidas: %d /n Cantidad de ventas mayores a 10000: %d /n Cantidad de ventas mayores a 20000: %d /n Cantidad de LCD vendidos: %d ",ll_count(this,cantVentas),ll_count(this,cantVentasMayoresA10000),ll_count(this,cantVentasMayoresA20000),ll_count(this,cantLCD));

}

////////////////////////////INFORMES////////////////////////////////////////////
int cantVentas(void* pElement)
{
	int returnAux=0;
	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVenta_getCantidad(pElement, &returnAux);
	}
	return returnAux;
}

int cantVentasMayoresA10000(void* pElement)
{
	int returnAux=0,cant;
	float monto,precio;

	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVenta_getCantidad(pElement, &cant);
		eVenta_getPrecio(pElement,&precio);
		monto=cant*precio;
		if(monto>10000)
		{
			returnAux=1;
		}
	}
	return returnAux;
}

int cantVentasMayoresA20000(void* pElement)
{
	int returnAux=0,cant;
	float monto,precio;

	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVenta_getCantidad(pElement, &cant);
		eVenta_getPrecio(pElement,&precio);
		monto=cant*precio;
		if(monto>20000)
		{
			returnAux=1;
		}
	}
	return returnAux;
}

int cantLCD(void* pElement)
{
	char desc[20];
	int returnAux=0;
	if(pElement!=NULL)
	{
		pElement=(eVentas*) pElement;
		eVenta_getCodigoProducto(pElement, desc);

		if(strcmp(desc,"LCD_TV")==0)
		{
			eVenta_getCantidad(pElement,&returnAux);
		}
	}
	return returnAux;
}

