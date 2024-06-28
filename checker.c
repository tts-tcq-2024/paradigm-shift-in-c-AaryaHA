#include <stdio.h>
#include <assert.h>

#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

typedef enum {
    OK,
    TEMPERATURE_OUT_OF_RANGE,
    SOC_OUT_OF_RANGE,
    CHARGE_RATE_OUT_OF_RANGE
} BatteryStatus;

BatteryStatus checkTemperature(float temperature) {
    if (temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX) {
        return TEMPERATURE_OUT_OF_RANGE;
    }
    return OK;
}

BatteryStatus checkSoc(float soc) {
    if (soc < SOC_MIN || soc > SOC_MAX) {
        return SOC_OUT_OF_RANGE;
    }
    return OK;
}

BatteryStatus checkChargeRate(float chargeRate) {
    if (chargeRate > CHARGE_RATE_MAX) {
        return CHARGE_RATE_OUT_OF_RANGE;
    }
    return OK;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    BatteryStatus tempStatus = checkTemperature(temperature);
    if (tempStatus != OK) {
        printf("Temperature out of range!\n");
        return 0;
    }

    BatteryStatus socStatus = checkSoc(soc);
    if (socStatus != OK) {
        printf("State of Charge out of range!\n");
        return 0;
    }

    BatteryStatus chargeRateStatus = checkChargeRate(chargeRate);
    if (chargeRateStatus != OK) {
        printf("Charge Rate out of range!\n");
        return 0;
    }

    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
