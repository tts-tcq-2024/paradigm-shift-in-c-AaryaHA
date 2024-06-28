#include <stdio.h>
#include <assert.h>

#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int ok = 1; // Assume everything is OK unless proven otherwise

    // Check temperature and state of charge together
    if (temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX ||
        soc < SOC_MIN || soc > SOC_MAX) {
        if (temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX) {
            printf("Temperature out of range!\n");
        }
        if (soc < SOC_MIN || soc > SOC_MAX) {
            printf("State of Charge out of range!\n");
        }
        ok = 0;
    }

    // Check charge rate
    if (chargeRate > CHARGE_RATE_MAX) {
        printf("Charge Rate out of range!\n");
        ok = 0;
    }

    return ok;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
