typedef struct
{
    int id_venta;
    char nombrePelicula[50];
    int dia;
    char horario[6];
    int sala;
    int cantidadEntradas;
    float monto;
}eVentas;
#include "LinkedList.h"

void eVentas_delete(eVentas* this);
eVentas* mapearVentas(eVentas* this);
int eVenta_setId(eVentas* this,int id);
int eVenta_getId(eVentas* this,int* id);
int eVenta_setPelicula(eVentas* this,char* auxPelicula);
int eVenta_getPelicula(eVentas* this,char* auxPelicula);
int eVenta_setHorario(eVentas* this,char* auxHorario);
int eVenta_getHorario(eVentas* this,char* auxHorario);
int eVenta_setDia(eVentas* this,int auxDia);
int eVenta_getDia(eVentas* this,int* auxDia);
int eVenta_getCantidad(eVentas* this,int* auxSala);
int eVenta_setSala(eVentas* this,int auxSala);
int eVenta_getSala(eVentas* this,int* auxSala);
int eVenta_setCantEntradas(eVentas* this,int auxCantEntradas);
int eVenta_getCantEntradas(eVentas* this,int* auxCantEntradas);
int eVenta_setMonto(eVentas* this, float auxMonto);
int eVenta_getPrecio(eVentas* this, float* auxMonto);
eVentas* eVenta_new();
eVentas* eVenta_newParametros(char* idStr,char* nombreStr,char* diasStr,char* horarioStr,char* salaStr, char* cantEntradasStr);
int eVentas_isValid(eVentas* pAux);
void showHeaderVentasSinMonto();
int printVentas(eVentas* this);
void* eVenta_llmap(void* pAux);
void descDias(char* auxDia,int* dia);
void* eVenta_cantEntradasPorSala(void* pAux,LinkedList* this);
/*int compareByName(void* eDom1, void* eDom2);
int eCachorro_filthA(void* pAux);
void* eCachorro_llmap(void* pAux);
int eCachorro_filterM(void* pAux);
void* eCachorro_llMotos(void* pAux);
int eCachorro_filterAuto(void* pAux);
int eCachorro_getReserva(eVentas* this,char* reservado);
int eCachorro_getGenero(eVentas* this,char* auxPelicula);
int eCachorro_filthMenos45Dias(void* pAux);
int eCachorro_filthMachos(void* pAux);
int eCachorro_filterCallejeros(void* pAux);
int eCachorro_getNombre(eVentas* this,char* auxNom);
int eCachorro_getDias(eVentas* this,int* dias);
int eCachorro_getRaza(eVentas* this,char* auxRaza);
*/
//eDominio_acumuladorAutos(void* pAux,eCachorro* lista);
