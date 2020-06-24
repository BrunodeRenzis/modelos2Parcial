#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "parser.h"
#include "eVentas.h"


int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    char buffer[6][30];
    int cant,todoOk=0;
    eVentas* pAux;

    if(pFile!=NULL && pArrayList!=NULL)
    {
        cant = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);

        while(!feof(pFile))
        {
        	cant = fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);
            pAux=eVenta_newParametros(buffer[0], buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);

            if(pAux!=NULL && pFile!=NULL && pArrayList !=NULL)
            {
                ll_add(pArrayList,pAux);
                todoOk=1;
            }
            if(cant < 6)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    todoOk=0;
                    break;
                }
            }
        }
    }
    return todoOk;
}
