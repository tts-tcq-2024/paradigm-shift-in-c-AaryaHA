#include "Battery_check.h"
#include "Temperature_range_check.h"
#include "SOC_range_check.h"
#include "ChargeRate_range_check.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) && isSocOk(soc) && isChargeRateOk(chargeRate);
}
