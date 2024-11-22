#define MaxProd 5 
void configurarPresupuestoYTiempo(float *presupuesto, float *Tdisponible, int *confPresupuestoyT); 
void imprimirProductos(int NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]);
void agregarProducto(int *NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]);
int buscarProductoPorNombre(const char nombreBuscado[], int NumProd, char NombresP[][50]);
void editarProducto(int NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]);
void eliminarProducto(int *NumProd, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]);
void calcularProduccion(int NumProd, float presupuesto, float Tdisponible, char NombresP[][50], float Costos[], float Tiempos[], int Demandas[]);
