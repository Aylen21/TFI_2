#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para el paciente
struct Paciente {
    char apellido[50];
    char nombres[50];
    char dni[20];
    char domicilio[100];
    int edad;
    float peso;
    float talla;
};

// Definición de la estructura para la historia clínica
struct HistoriaClinica {
    char fechaAtencion[20];
    char nombreProfesional[100];
    char historia[380];
};

// Función para buscar un paciente por apellido y nombre
struct Paciente buscarPaciente(struct Paciente pacientes[], int numPacientes, char apellidoBuscar[], char nombresBuscar[]) {
    struct Paciente pacienteEncontrado;
    pacienteEncontrado.apellido[0] = '\0'; // Inicializa en vacío

    for (int i = 0; i < numPacientes; ++i) {
        if (strcmp(pacientes[i].apellido, apellidoBuscar) == 0 && strcmp(pacientes[i].nombres, nombresBuscar) == 0) {
            pacienteEncontrado = pacientes[i];
            break;
        }
    }

    return pacienteEncontrado;
}

int main() {
    // Definir la lista de pacientes
    struct Paciente pacientes[100]; // Supongamos un máximo de 100 pacientes
    int numPacientes = 0; // Contador de pacientes

    // Definir la lista de historias clínicas
    struct HistoriaClinica historias[100]; // Supongamos un máximo de 100 historias
    int numHistorias = 0; // Contador de historias clínicas

    // Menú de inicio de sesión
    char usuario[50];
    char contrasena[50];
    printf("Ingrese su nombre de usuario: ");
    scanf("%s", usuario);
    printf("Ingrese su contraseña: ");
    scanf("%s", contrasena);

    // Aquí iría la lógica para verificar el usuario y contraseña

    // Simulamos algunos datos de pacientes para propósitos de prueba
    // Se pueden ingresar desde un archivo o base de datos en una implementación real
    strcpy(pacientes[numPacientes].apellido, "Gonzalez");
    strcpy(pacientes[numPacientes].nombres, "Juan");
    strcpy(pacientes[numPacientes].dni, "12345678");
    strcpy(pacientes[numPacientes].domicilio, "Calle 123");
    pacientes[numPacientes].edad = 30;
    pacientes[numPacientes].peso = 70.5;
    pacientes[numPacientes].talla = 1.75;
    numPacientes++;

    // Simulamos la búsqueda de un paciente por apellido y nombre
    char apellidoBuscar[50];
    char nombresBuscar[50];
    printf("\nIngrese el apellido del paciente a buscar: ");
    scanf("%s", apellidoBuscar);
    printf("Ingrese los nombres del paciente a buscar: ");
    scanf("%s", nombresBuscar);

    struct Paciente pacienteEncontrado = buscarPaciente(pacientes, numPacientes, apellidoBuscar, nombresBuscar);

    if (strlen(pacienteEncontrado.apellido) == 0) {
        printf("Paciente no encontrado.\n");
    } else {
        printf("\nPaciente encontrado:\n");
        printf("Apellido y Nombres: %s %s\n", pacienteEncontrado.apellido, pacienteEncontrado.nombres);
        printf("DNI: %s\n", pacienteEncontrado.dni);
        printf("Domicilio: %s\n", pacienteEncontrado.domicilio);
        printf("Edad: %d\n", pacienteEncontrado.edad);
        printf("Peso: %.2f\n", pacienteEncontrado.peso);
        printf("Talla: %.2f\n", pacienteEncontrado.talla);

        // Simulamos la creación de una historia clínica para el paciente encontrado
        printf("\nIngrese la fecha de atención (DD/MM/AAAA): ");
        scanf("%s", historias[numHistorias].fechaAtencion);
        printf("Ingrese su nombre como profesional: ");
        scanf("%s", historias[numHistorias].nombreProfesional);
        printf("Ingrese la historia clínica (máximo 380 caracteres): ");
        scanf(" %[^\n]s", historias[numHistorias].historia); // Leemos hasta encontrar un salto de línea
        numHistorias++;

        // Aquí iría la lógica para eliminar al paciente del listado de pendientes
    }

    return 0;
}