#include <stdio.h>

int main() {
    float V, Ra, k, Tmax;
    float T, Ia, Eb, N;
    int i;

    // -------- INPUT --------
    printf("Enter Supply Voltage (V): ");
    if (scanf("%f", &V) != 1 || V <= 0) {
        printf("Invalid input for Voltage!\n");
        return 0;
    }

    printf("Enter Armature Resistance (Ohms): ");
    if (scanf("%f", &Ra) != 1 || Ra <= 0) {
        printf("Invalid input for Resistance!\n");
        return 0;
    }

    printf("Enter Motor Constant (k): ");
    if (scanf("%f", &k) != 1 || k <= 0) {
        printf("Invalid input for k!\n");
        return 0;
    }

    printf("Enter Maximum Torque (Nm): ");
    if (scanf("%f", &Tmax) != 1 || Tmax <= 0) {
        printf("Invalid input for Torque!\n");
        return 0;
    }

    // -------- CALCULATION --------
    float step = Tmax / 20;

    printf("\nTorque (Nm)\tSpeed (RPM)\n");
    printf("-------------------------------\n");

    for (i = 1; i <= 20; i++) {
        T = i * step;

        Ia = T / k;          // Armature current
        Eb = V - Ia * Ra;    // Back EMF

        if (Eb <= 0) {
            break;
        }

        N = k * Eb;          // Speed

        printf("%0.2f\t\t%0.2f\n", T, N);
    }

    printf("\nNote: Speed decreases as Torque increases.\n");

    return 0;
}
