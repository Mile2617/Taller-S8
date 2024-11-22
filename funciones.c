#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MaxProd 5 

void configurarPresupuestoYTiempo(float *presupuesto, float *Tdisponible, int *confPresupuestoyT) {
    printf("\nIngrese el presupuesto general (Dolares): ");
    scanf("%f", presupuesto);
    printf("Ingrese el tiempo total disponible (Horas): ");
    scanf("%f", Tdisponible);
    *confPresupuestoyT = 1;
}

void imprimirProductos(int NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]) {
    if (NumProd == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }
    printf("\n --------Tabla de productos--------\n");
    printf("Num.\tNombre\t\tCosto\t\tTiempo\t\tDemanda\n");
    for (int i = 0; i < NumProd; i++) {
        printf("%d\t%s\t\t $ %.2f\t\t%.2f h\t\t%d u\n", i + 1, NombresP[i], Costos[i], Tiempos[i], Demandas[i]);
    }
}

void agregarProducto(int *NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]) {
    if (*NumProd >= MaxProd) {
        printf("No se pueden agregar mas productos.\n");
        return;
    }
    printf("\nIngrese el nombre del producto: ");
    fflush(stdin);
    fgets(NombresP[*NumProd], 50, stdin);
    size_t length = strlen(NombresP[*NumProd]);
    if (length > 0 && NombresP[*NumProd][length - 1] == '\n') {
        NombresP[*NumProd][length - 1] = '\0';
    }
    do {
        printf("Ingrese el costo de produccion del producto (Dolares): ");
        scanf("%f", &Costos[*NumProd]);
    } while (Costos[*NumProd] <= 0);
    do {
        printf("Ingrese el tiempo de fabricacion del producto (Horas): ");
        scanf("%f", &Tiempos[*NumProd]);
    } while (Tiempos[*NumProd] <= 0);
    do {
        printf("Ingrese la demanda del producto (Unidades): ");
        scanf("%d", &Demandas[*NumProd]);
    } while (Demandas[*NumProd] <= 0);

    (*NumProd)++;
    printf("\nProducto agregado exitosamente.\n");
}

int buscarProductoPorNombre(const char nombreBuscado[], int NumProd, char NombresP[][50]) {
    for (int i = 0; i < NumProd; i++) {
        if (strcmp(NombresP[i], nombreBuscado) == 0) {
            return i;
        }
    }
    return -1;
}

void editarProducto(int NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]) {
    char nombreBuscado[50];
        printf("\nIngrese el nombre del producto a editar: ");
    fflush(stdin);
    fgets(nombreBuscado, 50, stdin);
    size_t length = strlen(nombreBuscado);
    if (length > 0 && nombreBuscado[length - 1] == '\n') {
        nombreBuscado[length - 1] = '\0';
    }
    int indicador = buscarProductoPorNombre(nombreBuscado, NumProd, NombresP);
    if (indicador == -1) {
        printf("\nProducto '%s' no encontrado.\n", nombreBuscado);
        return;
    }
    printf("Producto encontrado. Ingrese los nuevos valores.\n");
    do {
        printf("Ingrese el nuevo costo de produccion (Dolares): ");
        scanf("%f", &Costos[indicador]);
    } while (Costos[indicador] <= 0);
    do {
        printf("Ingrese el nuevo tiempo de fabricacion (Horas): ");
        scanf("%f", &Tiempos[indicador]);
    } while (Tiempos[indicador] <= 0);
    do {
        printf("Ingrese la nueva demanda (Unidades): ");
        scanf("%d", &Demandas[indicador]);
    } while (Demandas[indicador] <= 0);

    printf("\nProducto editado exitosamente.\n");
}

void eliminarProducto(int *NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]) {
    char nombreBuscado[50];
    printf("\nIngrese el nombre del producto a eliminar: ");
    fflush(stdin);
    fgets(nombreBuscado, 50, stdin);
    size_t length = strlen(nombreBuscado);
    if (length > 0 && nombreBuscado[length - 1] == '\n') {
        nombreBuscado[length - 1] = '\0';
    }
    int indicador = buscarProductoPorNombre(nombreBuscado, *NumProd, NombresP);
    if (indicador == -1) {
        printf("\nProducto '%s' no encontrado.\n", nombreBuscado);
        return;
    }
    for (int i = indicador; i < *NumProd - 1; i++) {
        strcpy(NombresP[i], NombresP[i + 1]);
        Costos[i] = Costos[i + 1];
        Tiempos[i] = Tiempos[i + 1];
        Demandas[i] = Demandas[i + 1];
    }
    
    (*NumProd)--;
    printf("\nProducto eliminado exitosamente.\n");
}

void calcularProduccion(int NumProd, float presupuesto, float Tdisponible, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]) {
    float TiempoT = 0, CostoT = 0;

    for (int i = 0; i < NumProd; i++) {
        TiempoT += Tiempos[i] * Demandas[i];
        CostoT += Costos[i] * Demandas[i];
    }
    printf("Costo total requerido: %.2f\n", CostoT);
    printf("Tiempo total requerido: %.2f horas\n", TiempoT);
    if (TiempoT > Tdisponible && CostoT > presupuesto) {
        printf("No se puede cumplir con la demanda: falta tiempo y presupuesto.\n");
    } else if (TiempoT > Tdisponible) {
        printf("No se puede cumplir con la demanda: falta tiempo.\n");
    } else if (CostoT > presupuesto) {
        printf("No se puede cumplir con la demanda: falta presupuesto.\n");
    } else {
        printf("La fabrica puede cumplir con la demanda.\n");
    }
}
