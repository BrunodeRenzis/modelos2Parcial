#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "Controller.h"
#include "eVentas.h"
#include "parser.h"
#include "validaciones.h"
#include "Save.h"
#include "utn.h"
int informePorSala(LinkedList* this)
{
	int todoOk=0;
	int i,j,sala,salaIngresada,contador,acumuladorEntradas=0;
	float total=0,montoAcumulado;
	int entradas;
	LinkedList* listaPeliculas= ll_newLinkedList();
	eVentas* pAux;
	char* peliculaAux;
	char pelicua[30];
	if(this!=NULL)
	{
		ll_map(this,eVenta_llmap);
		if(utn_getEntero(&salaIngresada,4,"\nIngrese numero de sala\n","\nError ingrese numero nuevamente: ",1,5))
		{
			for(i=0; i<ll_len(this); i++)
			{
				pAux=ll_get(this,i);
				eVenta_getSala(pAux,&sala);
				if(sala==salaIngresada)
				{
					contador=0;
					eVenta_getPelicula(pAux,pelicua); //obtengo el nombre de la peli de la sala ingresada
					for(j=0; j<ll_len(listaPeliculas);j++)// recorro la linkedlist de peliculas
					{
						peliculaAux=ll_get(listaPeliculas,j);
						if(strcmp(peliculaAux,pelicua)==0)
						{
							contador++;
							break;
						}
					}
					if(contador==0)// si no esta en la lista reservo memoria y la cargo a la linkedlist de peliculas
					{
						char* pelicula=(char*) malloc(sizeof(char)*30);
						strcpy(pelicula,pelicua);
						ll_add(listaPeliculas,pelicula);
					}
					eVenta_getCantEntradas(pAux,&entradas);
					eVenta_getPrecio(pAux,&montoAcumulado);
					acumuladorEntradas+=entradas;
					total+=montoAcumulado;
				}
			}
		}
		printf("\n\nLa cantidad de entradas de la sala %d es %d\n", salaIngresada,acumuladorEntradas);
		printf("\n\nEl total es %.2f\n", total);
		printf("\n\nLas peliculas de la sala son:\n");

		for(j=0; j<ll_len(listaPeliculas);j++)
		{
			peliculaAux=ll_get(listaPeliculas,j);
			printf("%s\n",peliculaAux);
		}
	}
	return todoOk;
}
