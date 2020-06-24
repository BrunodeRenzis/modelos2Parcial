typedef struct
{
    int id_venta;
    char fechaVenta[14];
    char codigoProducto[50];
    int cantidad;
    float precioUnitario;
    char cuit[15];
}eVentas;
#include "LinkedList.h"

void eVentas_delete(eVentas* this);
eVentas* mapearVentas(eVentas* this);
int eVenta_setId(eVentas* this,int id);
int eVenta_getId(eVentas* this,int* id);
int eVenta_setFechaVenta(eVentas* this,char* auxFecha);
int eVenta_getFechaVenta(eVentas* this,char* auxFecha);
int eVenta_setCodigoProducto(eVentas* this,char* auxCodigoProducto);
int eVenta_getCodigoProducto(eVentas* this,char* auxCodigoProducto);
int eVenta_setCantidad(eVentas* this,int auxCantidad);
int eVenta_getCantidad(eVentas* this,int* auxCantidad);
int eVenta_setPrecio(eVentas* this, float auxPrecio);
int eVenta_getPrecio(eVentas* this, float* auxPrecio);
int eVenta_setCuit(eVentas* this,char* auxCuit);
int eVenta_getCuit(eVentas* this,char* auxCuit);
eVentas* eVenta_new();
eVentas* eVenta_newParametros(char* idStr,char* fechaStr,char* codigoStr,char* cantidadStr,char* precioUniStr, char* cuitStr);
int eVentas_isValid(eVentas* pAux);
void showHeaderVentasSinMonto();
int printVentas(eVentas* this);
void* eVenta_llmap(void* pAux);
