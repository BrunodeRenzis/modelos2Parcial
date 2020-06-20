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
#include "informes.h"
int main()
{
	setbuf(stdout,NULL);
    LinkedList* listaPeliculas = ll_newLinkedList();
    LinkedList* peliculaConMontos = NULL;
    char seguir='s', path[20];
    if(listaPeliculas!=NULL)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    utn_getCadena(path,20,20,"Ingresar nombre del archivo\n","Error, ingresar un path correcto\n");
                    if(controller_loadFromText(path,listaPeliculas)==1)
                    {
                        printf("\nlista cargada correctamente!");
                    }
                    else
                    {
                        printf("Error al cargar los datos");
                    }

                    break;
                case 2:
                    if(!(ll_isEmpty(listaPeliculas)==1))
                    {
                        controller_List(listaPeliculas);
                    }
                    else
                    {
                        puts("No se pudo mostrar la lista");
                    }

                    break;

                case 3:
                    if(!(ll_isEmpty(listaPeliculas)==1))
                      {
                          peliculaConMontos = ll_map(listaPeliculas,eVenta_llmap);
                          if(listaPeliculas!=NULL)
                          {
                              if(saveAsText("pelisConMonto.csv",peliculaConMontos)==1)
                              {
                                  printf("Lista creada");
                              }
                          }
                      }
                      else
                      {
                          printf("Error al cargar los datos");
                      }

                    break;

                case 4:
                    if(!(ll_isEmpty(listaPeliculas)==1))
                      {
                    	informePorSala(listaPeliculas);
                      }

                      else
                      {
                          printf("Error al cargar los datos");
                      }

                	break;

                case 5:
                    seguir='n';
                    break;
                }
                system("pause");

            }
            while(seguir=='s');

    }
    return 0;
}
