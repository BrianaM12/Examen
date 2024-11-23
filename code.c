#include <stdio.h>
#include <cs50.h>

int main() {
    int num1, num2, op;
    char continuar; // Variable para decidir si continuar

    do {
        // 1. Validar rango
        do {
            num1 = get_int("Ingrese el primer número: ");
            num2 = get_int("Ingrese el segundo número: ");

            if (num1 > num2) {
                printf("Error: el primer número debe ser menor o igual al segundo. Inténtelo de nuevo.\n");
            }
        } while (num1 > num2); // Repetir mientras num1 sea mayor que num2

        printf("Rango válido: %d es menor o igual a %d\n\n", num1, num2);

        // 2. Elegir una operación
        printf("===Menu===\n");
        printf("1. Mostrar todos los números pares en el rango y calcular su suma\n");
        printf("2. Mostrar todos los números impares en el rango y calcular su suma\n");
        printf("3. Mostrar tanto los números pares como los impares y calcular su suma\n");
        printf("4. Salir\n");

        op = get_int("Seleccione una opción: ");

        // 3. Identificar y mostrar números
        int sumaPares = 0, sumaImpares = 0;

        switch (op) {
            case 1: // Números pares
                printf("Números pares en el rango [%d, %d]:\n", num1, num2);
                for (int i = num1; i <= num2; i++) {
                    if (i % 2 == 0) {
                        printf("%d ", i);
                        sumaPares += i;
                    }
                }
                printf("\nSuma de números pares: %d\n", sumaPares);
                break;

            case 2: // Números impares
                printf("Números impares en el rango [%d, %d]:\n", num1, num2);
                for (int i = num1; i <= num2; i++) {
                    if (i % 2 != 0) {
                        printf("%d ", i);
                        sumaImpares += i;
                    }
                }
                printf("\nSuma de números impares: %d\n", sumaImpares);
                break;

            case 3: // Números pares e impares
                printf("Números pares en el rango [%d, %d]:\n", num1, num2);
                for (int i = num1; i <= num2; i++) {
                    if (i % 2 == 0) {
                        printf("%d ", i);
                        sumaPares += i;
                    }
                }
                printf("\nSuma de números pares: %d\n", sumaPares);

                printf("\nNúmeros impares en el rango [%d, %d]:\n", num1, num2);
                for (int i = num1; i <= num2; i++) {
                    if (i % 2 != 0) {
                        printf("%d ", i);
                        sumaImpares += i;
                    }
                }
                printf("\nSuma de números impares: %d\n", sumaImpares);
                break;

            case 4: // Salir
                printf("Saliendo del programa...\n");
                return 0;

            default: // Opción inválida
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }

        // Preguntar si el usuario desea continuar
        continuar = get_char("¿Desea realizar otra operación? (s/n): ");

    } while (continuar == 's' || continuar == 'S'); // Repetir si la respuesta es 's' o 'S'

    printf("Programa finalizado. ¡Hasta luego!\n");
    return 0;
}
