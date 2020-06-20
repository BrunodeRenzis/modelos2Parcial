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
int eVenta_setPelicula(eVentas* this,char* auxNom)
{
    int todoOk=0;
    if(this!=NULL && auxNom!=NULL)
    {
        strcpy(this->nombrePelicula,auxNom);
        todoOk=1;
    }
    return todoOk;
}

int eVenta_getPelicula(eVentas* this,char* auxNom)
{
    int todoOk=0;
    //printf("AuxNom antes: %s",auxNom);
    if(this!=NULL && auxNom!=NULL)
    {
        strcpy(auxNom, this->nombrePelicula);
        todoOk=1;
    }
    //printf("AuxNom Despues: %s",auxNom);
    return todoOk;
}
//////////////////////////////////////////////////////

////////////////////////////////////////////GET Y SET DIAS
int eVenta_setDia(eVentas* this,int auxDias)
{
    int todoOk=0;
    //printf("auxDias %d\n\n\n\n",auxDias);
    if(this!=NULL && auxDias>=0)
    {
        //printf("auxDias %d\n",auxDias);
        this->dia=auxDias;
        todoOk=1;
    }
    //printf("diasCachorro %d",this->dias);
    return todoOk;
}

int eVenta_getDia(eVentas* this,int* auxDias)
{
    int todoOk=0;
    if(this!=NULL && auxDias!=NULL)
    {
        *auxDias=this->dia;
        todoOk=1;
    }
    return todoOk;
}

int eVenta_setHorario(eVentas* this,char* auxHorario)
{
    int todoOk=0;

    if(this!=NULL && auxHorario!=NULL)
    {
        strcpy(this->horario,auxHorario);
        todoOk=1;
    }

    return todoOk;
}

int eVenta_getHorario(eVentas* this,char* auxHorario)
{

    int todoOk=0;
    if(this!=NULL)
    {
        strcpy(auxHorario,this->horario);
        todoOk=1;
    }
    return todoOk;
}

int eVenta_setSala(eVentas* this,int auxSala)
{
    int todoOk=0;
    if(this!=NULL)
    {
        this->sala = auxSala;
        todoOk=1;
    }
    return todoOk;
}

int eVenta_getSala(eVentas* this,int* auxSala)
{
    int todoOk=0;
    if(this!=NULL && auxSala!=NULL)
    {
    	*auxSala=this->sala;
        todoOk=1;
    }
    return todoOk;
}

int eVenta_setCantEntradas(eVentas* this,int auxCantEntradas)
{
    int todoOk=0;
    if(this!=NULL)
    {
        this->cantidadEntradas=auxCantEntradas;
        todoOk=1;
    }
    return todoOk;
}

int eVenta_getCantEntradas(eVentas* this,int* auxCantEntradas)
{
    int todoOk=0;
    if(this!=NULL && auxCantEntradas!=NULL)
    {
    	*auxCantEntradas=this->cantidadEntradas;
        todoOk=1;
    }
    return todoOk;
}

int eVenta_setMonto(eVentas* this, float auxMonto)
{
    int todoOk=0;

    if(this!=NULL)
    {
    	this->monto=auxMonto;
        todoOk=1;
    }

    return todoOk;
}

int eVenta_getPrecio(eVentas* this, float* auxMonto)
{
    int todoOk=0;

    if(this!=NULL && auxMonto!=NULL)
    {
    	*auxMonto=this->monto;
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
        strcpy(newVenta->nombrePelicula," ");
        newVenta->dia=0;
        strcpy(newVenta->horario," ");
        newVenta->sala=0;
        newVenta->cantidadEntradas=0;
        //newVenta->monto=0;
    }
    else
    {
        eVentas_delete(newVenta);
        newVenta=NULL;
    }
    return newVenta;

}


eVentas* eVenta_newParametros(char* idStr,char* nombreStr,char* diasStr,char* horarioStr,char* salaStr, char* cantEntradasStr)
{
    eVentas* newVenta;
    newVenta=eVenta_new();
    if(idStr!=NULL && horarioStr!=NULL && salaStr!=NULL && diasStr!=NULL &&nombreStr!=NULL && cantEntradasStr!=NULL)
    {
        if(eVenta_setId(newVenta,atoi(idStr))==0||
                eVenta_setHorario(newVenta,horarioStr)==0||
                eVenta_setDia(newVenta,atoi(diasStr))==0||
                eVenta_setSala(newVenta,atoi(salaStr))==0||
                eVenta_setPelicula(newVenta,nombreStr)==0||
                eVenta_setCantEntradas(newVenta,atoi(cantEntradasStr))==0/*||
				eVenta_setMonto(newVenta,atof(montoStr))==0*/)
        {
            eVentas_delete(newVenta);
            newVenta=NULL;
        }
    }
    return newVenta;
}

int eVenta_isValid(eVentas* pAux)
{
    int todoOk=0,id,dia,sala,cantEntradas;
    //float monto;
    char horario[10];
    char nombre[50];

    if(pAux!=NULL)
    {
        eVenta_getId(pAux,&id);
        eVenta_getPelicula(pAux,nombre);
        eVenta_getDia(pAux,&dia);
        eVenta_getHorario(pAux,horario);
        eVenta_getSala(pAux,&sala);
        eVenta_getCantEntradas(pAux,&cantEntradas);
        //eVenta_getMonto(pAux,&monto);
        if(id>0 && dia >=0 && dia<=6 && horario!=NULL && nombre !=NULL && cantEntradas>=0 && sala>0 && sala<=5)
        {
            todoOk=1;
        }
    }
    return todoOk;
}

void showHeaderVentasSinMonto()
{
	printf("ID VENTA       PELICULA      DIA       HORA    SALA    CANT ENTRADAS\n");
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
    int todoOk=0,id,dias,sala,cantEntradas;
    char nombre[20], horario[10],descDia[10];


    if(this!=NULL)
    {
        eVenta_getId(this,&id);
        eVenta_getPelicula(this,nombre);
        eVenta_getDia(this,&dias);
        eVenta_getHorario(this,horario);
        eVenta_getSala(this,&sala);
        eVenta_getCantEntradas(this,&cantEntradas);
        descDias(descDia,&dias);
        printf("%5d %20s %5s %11s %5d %10d\n",id,nombre,descDia,horario,sala,cantEntradas);
        todoOk=1;
    }

    return todoOk;
}

void* eVenta_llmap(void* pAux)
{

    if(pAux!= NULL)
    {
    	float monto;
        eVentas* pelicula=(eVentas*)pAux;
        int diaPelicula,cantEntradas,total;
        eVenta_getDia(pelicula,&diaPelicula);
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
        eVenta_setMonto(pelicula,total);
    }
    return pAux;
}


/////////////////////////////////INFORMES/////////////////////////////////


/*
int eCachorro_filthMachos(void *pAux)
{
    int todoOk = 0;
    char aux[3];
    if(pAux!=NULL)
    {
        eCachorro_getGenero(pAux,aux);
        if(strcmp(aux,"H")==0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}


int eCachorro_filthMenos45Dias(void* pAux)
{
    int todoOk = 0;
    int auxDias;
    if(pAux!=NULL)
    {
        eCachorro_getDias(pAux,&auxDias);
        if(auxDias<45)
        {
            todoOk=1;
        }
        else
        {
            todoOk=-1;
        }
    }
    return todoOk;
}

int eCachorro_filterCallejeros(void* pAux)
{
    int todoOk = 0;
    char auxRaza[20];
    char aux[20];
    if(pAux!=NULL)
    {
        eCachorro_getRaza(pAux,auxRaza);
        for(int i=0; i<strlen(auxRaza); i++)
        {
            if(strcmp(auxRaza,"Callejero")==0)
            {
                strcpy(aux,auxRaza);
                todoOk=1;
            }
        }

    }
    return todoOk;
}
*/
