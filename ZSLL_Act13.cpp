#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTROS 5000

typedef struct {
    int status;
    char nombre[50];
    char matricula[50];
    char apPat[50];
    char apMat[50];
    int edad;
    char sexo;
} Empleado;

typedef struct {
    Empleado registros[MAX_REGISTROS];
    int cantidad;
} VectorRegistros;

void swap(Empleado *x, Empleado *y);

void agregarRegistros(VectorRegistros *vector);
void editarRegistro(VectorRegistros *vector);
void eliminarRegistro(VectorRegistros *vector);
void buscarRegistro(VectorRegistros *vector);
void ordenarRegistros(VectorRegistros *vector);
void quicksort(Empleado arr[], int inicio, int fin);
int particion(Empleado arr[], int inicio, int fin);
void imprimirRegistros(VectorRegistros *vector);
void generarArchivoTexto(VectorRegistros *vector);
void verArchivoTexto();
void crearArchivoBinario(VectorRegistros *vector);
void cargarArchivoBinario(VectorRegistros *vector);
void mostrarEliminados();

int main() {
    VectorRegistros vector;
    vector.cantidad = 0;

    int opcion;
    do {
        printf("MENÚ\n");
        printf("1. Agregar\n");
        printf("2. Editar Registro\n");
        printf("3. Eliminar Registro\n");
        printf("4. Buscar\n");
        printf("5. Ordenar\n");
        printf("6. Imprimir\n");
        printf("7. Generar Archivo Texto\n");
        printf("8. Mostrar Archivo Texto\n");
        printf("9. Crear Archivo Binario\n");
        printf("10. Cargar Archivo Binario\n");
        printf("11. Mostrar Eliminados\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            agregarRegistros(&vector);
            break;
        case 2:
            editarRegistro(&vector);
            break;
        case 3:
            eliminarRegistro(&vector);
            break;
        case 4:
            buscarRegistro(&vector);
            break;
        case 5:
            ordenarRegistros(&vector);
            break;
        case 6:
            imprimirRegistros(&vector);
            break;
        case 7:
            generarArchivoTexto(&vector);
            break;
        case 8:
            verArchivoTexto();
            break;
        case 9:
            crearArchivoBinario(&vector);
            break;
        case 10:
            cargarArchivoBinario(&vector);
            break;
        case 11:
            mostrarEliminados();
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida. Intente nuevamente.\n");
            break;
        }

        printf("\n");
    } while (opcion != 0);

    return 0;
}

void agregarRegistros(VectorRegistros *vector) {
    for (int i = 0; i < 100; i++) {
        Empleado empleado;
        empleado.status = i + 1;
        sprintf(empleado.nombre, "Empleado %d: Fulano");
        sprintf(empleado.matricula, "Matricula %d:", i + 1);
        sprintf(empleado.apPat, "Apellido Paterno %d:Bolillo", i + 1);
        sprintf(empleado.apMat, "Apellido Materno %d:De Frijol", i + 1);
        empleado.edad = 25;
        empleado.sexo = 'M';
        vector->registros[vector->cantidad++] = empleado;
    }
}

void editarRegistro(VectorRegistros *vector) {
    int status;
    printf("Ingrese la matrícula del empleado a editar: ");
    scanf("%d", &status);
    for (int i = 0; i < vector->cantidad; i++) {
        if (vector->registros[i].status == status) {
            printf("Datos del empleado:\n");
            printf("Matrícula: %d\n", vector->registros[i].status);
            printf("Nombre: %s\n", vector->registros[i].nombre);
            printf("Matrícula: %s\n", vector->registros[i].matricula);
            printf("Apellido Paterno: %s\n", vector->registros[i].apPat);
            printf("Apellido Materno: %s\n", vector->registros[i].apMat);
            printf("Edad: %d\n", vector->registros[i].edad);
            printf("Sexo: %c\n", vector->registros[i].sexo);
            return;
        }
    }

    printf("No se encontró un empleado con la matrícula ingresada.\n");
}

void eliminarRegistro(VectorRegistros *vector) {
    int status;
    printf("Ingrese la matrícula del empleado a eliminar: ");
    scanf("%d", &status);
    for (int i = 0; i < vector->cantidad; i++) {
        if (vector->registros[i].status == status) {
            printf("Datos del empleado:\n");
            printf("Matrícula: %d\n", vector->registros[i].status);
            printf("Nombre: %s\n", vector->registros[i].nombre);
            printf("Matrícula: %s\n", vector->registros[i].matricula);
            printf("Apellido Paterno: %s\n", vector->registros[i].apPat);
            printf("Apellido Materno: %s\n", vector->registros[i].apMat);
            printf("Edad: %d\n", vector->registros[i].edad);
            printf("Sexo: %c\n", vector->registros[i].sexo);
            return;
        }
    }

    printf("No se encontró un empleado con la matrícula ingresada.\n");
}

void buscarRegistro(VectorRegistros *vector) {
    int status;
    printf("Ingrese la matrícula del empleado a buscar: ");
    scanf("%d", &status);

    for (int i = 0; i < vector->cantidad; i++) {
        if (vector->registros[i].status == status) {
            printf("Datos del empleado:\n");
            printf("Matrícula: %d\n", vector->registros[i].status);
            printf("Nombre: %s\n", vector->registros[i].nombre);
            printf("Matrícula: %s\n", vector->registros[i].matricula);
            printf("Apellido Paterno: %s\n", vector->registros[i].apPat);
            printf("Apellido Materno: %s\n", vector->registros[i].apMat);
            printf("Edad: %d\n", vector->registros[i].edad);
            printf("Sexo: %c\n", vector->registros[i].sexo);
            return;
        }
    }

    printf("No se encontró un empleado con la matrícula ingresada.\n");
}

void ordenarRegistros(VectorRegistros *vector) {
    quicksort(vector->registros, 0, vector->cantidad - 1);
}

void quicksort(Empleado arr[], int inicio, int fin) {
    int i, j, pivote;

    if (inicio < fin) {
        pivote = particion(arr, inicio, fin);
        quicksort(arr, inicio, pivote - 1);
        quicksort(arr, pivote + 1, fin);
    }
}

int particion(Empleado arr[], int inicio, int fin) {
    char pivote[50];
    strcpy(pivote, arr[fin].matricula);

    int i = (inicio - 1);

    for (int j = inicio; j <= fin - 1; j++) {
        if (strcmp(arr[j].matricula, pivote) <= 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[fin]);

    return (i + 1);
}

void swap(Empleado *x, Empleado *y) {
    Empleado temp = *x;
    *x = *y;
    *y = temp;
}

void imprimirRegistros(VectorRegistros *vector) {
    printf("Registros de empleados:\n");
    for (int i = 0; i < vector->cantidad; i++) {
        printf("Matrícula: %d\n", vector->registros[i].status);
        printf("Nombre: %s\n", vector->registros[i].nombre);
        printf("Matrícula: %s\n", vector->registros[i].matricula);
        printf("Apellido Paterno: %s\n", vector->registros[i].apPat);
        printf("Apellido Materno: %s\n", vector->registros[i].apMat);
        printf("Edad: %d\n", vector->registros[i].edad);
        printf("Sexo: %c\n", vector->registros[i].sexo);
        printf("\n");
    }
}

void generarArchivoTexto(VectorRegistros *vector) {
    char nombreArchivo[50];
    printf("Ingrese el nombre del archivo de texto (sin extensión): ");
    scanf("%s", nombreArchivo);

    char nombreCompleto[60];
    sprintf(nombreCompleto, "%s.txt", nombreArchivo);

    FILE *archivo = fopen(nombreCompleto, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo de texto.\n");
        return;
    }

    for (int i = 0; i < vector->cantidad; i++) {
        fprintf(archivo, "Matrícula: %d\n", vector->registros[i].status);
        fprintf(archivo, "Nombre: %s\n", vector->registros[i].nombre);
        fprintf(archivo, "Matrícula: %s\n", vector->registros[i].matricula);
        fprintf(archivo, "Apellido Paterno: %s\n", vector->registros[i].apPat);
        fprintf(archivo, "Apellido Materno: %s\n", vector->registros[i].apMat);
        fprintf(archivo, "Edad: %d\n", vector->registros[i].edad);
        fprintf(archivo, "Sexo: %c\n", vector->registros[i].sexo);
        fprintf(archivo, "\n");
    }

    fclose(archivo);
    printf("Se generó el archivo de texto correctamente.\n");
}

void verArchivoTexto() {
    char nombreArchivo[50];
    printf("Ingrese el nombre del archivo de texto (sin extensión): ");
    scanf("%s", nombreArchivo);

    char nombreCompleto[60];
    sprintf(nombreCompleto, "%s.txt", nombreArchivo);

    FILE *archivo = fopen(nombreCompleto, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de texto.\n");
        return;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }

    fclose(archivo);
}

void crearArchivoBinario(VectorRegistros *vector) {
    FILE *archivo = fopen("datos.bin", "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo binario.\n");
        return;
    }

    fwrite(vector->registros, sizeof(Empleado), vector->cantidad, archivo);

    fclose(archivo);
    printf("Se creó el archivo binario correctamente.\n");
}

void cargarArchivoBinario(VectorRegistros *vector) {
    FILE *archivo = fopen("datos.bin", "rb");
    if (archivo == NULL) {
        printf("El archivo binario no existe.\n");
        return;
    }

    fread(vector->registros, sizeof(Empleado), MAX_REGISTROS, archivo);

    fclose(archivo);
    printf("Se cargó el archivo binario correctamente.\n");
}

void mostrarEliminados() {
    FILE *archivo = fopen("datos.bin", "rb");
    if (archivo == NULL) {
        printf("El archivo binario no existe.\n");
        return;
    }

    Empleado empleado;
    while (fread(&empleado, sizeof(Empleado), 1, archivo)) {
        if (empleado.status == 0) {
            printf("Matrícula: %d\n", empleado.status);
            printf("Nombre: %s\n", empleado.nombre);
            printf("Matrícula: %s\n", empleado.matricula);
            printf("Apellido Paterno: %s\n", empleado.apPat);
            printf("Apellido Materno: %s\n", empleado.apMat);
            printf("Edad: %d\n", empleado.edad);
            printf("Sexo: %c\n", empleado.sexo);
            printf("\n");
        }
    }

    fclose(archivo);
}
