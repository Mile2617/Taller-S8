#include <stdio.h>
#include <string.h>
#include "funciones.h"


#define MaxProd 5 

int main() {
    int NumProd = 0; 
    float presupuesto = 0;
    float Tdisponible = 0;
    int confPresupuestoyT = 0;
    char NombresP[MaxProd][50];
    float Costos[MaxProd];
    float Tiempos[MaxProd];
    int Demandas[MaxProd];
    int Opc;

printf("\n");
printf("  --------                  SISTEMA DE PRODUCCION      --------         \n\n");
printf(" Bienvenido al sistema de gestion de produccion.          \n");
printf(" Aqui podra realizar las siguientes acciones:             \n");

    do {
        printf("\n--------Menu de opciones--------\n");
        printf("1. Agregar un producto\n");
        printf("2. Editar un producto\n");
        printf("3. Eliminar un producto\n");
        printf("4. Configurar presupuesto y tiempo de produccion que posee la empresa\n");
        printf("5. Calcular si la fabrica puede cumplir con la demanda\n");
        printf("6. Imprimir datos de productos\n");
        printf("7. Salir del programa\n");
        printf("Seleccione el numero de la opcion: ");
        scanf("%d", &Opc);

        switch (Opc) {
            case 1:
                agregarProducto(&NumProd, NombresP, Costos, Tiempos, Demandas);
                imprimirProductos(NumProd, NombresP, Costos, Tiempos, Demandas);
                break;
            case 2:
                    if (NumProd == 0) {
                      printf("\nNo hay productos registrados.\n");}
                    else {
                        editarProducto(NumProd, NombresP, Costos, Tiempos, Demandas);
                        imprimirProductos(NumProd, NombresP, Costos, Tiempos, Demandas);
                    }
                break;
            case 3:
            if (NumProd == 0) {
                      printf("\nNo hay productos registrados.\n");}
                    else {
                eliminarProducto(&NumProd, NombresP, Costos, Tiempos, Demandas);
                imprimirProductos(NumProd, NombresP, Costos, Tiempos, Demandas);
                }
                break;
            case 4:
                configurarPresupuestoYTiempo(&presupuesto, &Tdisponible, &confPresupuestoyT);
                break;
            case 5:
                if  (NumProd == 0) {
                printf("\nNo hay productos registrados.\n");}
                else {
                if (confPresupuestoyT) {
                    calcularProduccion(NumProd, presupuesto, Tdisponible, NombresP, Costos, Tiempos, Demandas);
                } else {
                    printf("\nDebe configurar el presupuesto y el tiempo antes de calcular la produccion.\n");
                }
                }
                break;
            case 6:
                imprimirProductos(NumProd, NombresP, Costos, Tiempos, Demandas);
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while (Opc != 7);

    return 0;
}
