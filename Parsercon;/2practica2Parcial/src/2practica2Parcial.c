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
    LinkedList* listaArticulos = ll_newLinkedList();
    //LinkedList* peliculaConMontos = NULL;
    char seguir='s', path[20];
    if(listaArticulos!=NULL)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    utn_getCadena(path,20,20,"Ingresar nombre del archivo\n","Error, ingresar un path correcto\n");
                    if(controller_loadFromText(path,listaArticulos)==1)
                    {
                        printf("\nlista cargada correctamente!");
                    }
                    else
                    {
                        printf("Error al cargar los datos");
                    }

                    break;
                case 2:
                    if(!(ll_isEmpty(listaArticulos)==1))
                    {
                        controller_List(listaArticulos);
                    }
                    else
                    {
                        puts("No se pudo mostrar la lista");
                    }

                    break;

                case 3:
                    if(!(ll_isEmpty(listaArticulos)==1))
                      {
                         menuInformes(listaArticulos);
                      }
                      else
                      {
                          printf("Error al cargar los datos");
                      }

                    break;


                case 4:
                    seguir='n';
                    break;
                }
                system("pause");

            }
            while(seguir=='s');

    }
    return 0;
}
