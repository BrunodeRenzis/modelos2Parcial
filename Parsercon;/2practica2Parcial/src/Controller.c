#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "eVentas.h"

int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    FILE* f;
    int todoOk=0;
    if(path!=NULL && pArrayList!=NULL)
    {
        strcat(path,".csv");
        f=fopen(path,"r");  //FOPEN ESTA DEVOLVIENDO 0

        if(f!=NULL)
        {
            parser_FromText(f,pArrayList);
            fclose(f);
            todoOk=1;
        }
        else
        {
            todoOk=0;
        }
    }
    return todoOk;
}



int controller_List(LinkedList* pArrayList)
{
    eVentas* aux;
    int todoOk=0;
    int len;

    if(pArrayList!=NULL){
        len=ll_len(pArrayList);
        showHeaderVentasSinMonto();
        for(int i=0;i<len;i++){
            aux=(eVentas*)ll_get(pArrayList,i);
            printVentas(aux);
            todoOk=1;
        }
    }

    return todoOk;
}
