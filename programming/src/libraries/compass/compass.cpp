#include "compass.h"
#include "../i2c/i2c.h"
#include "../debug/debug.h"
#include <iostream>
using namespace std;

Compass::Compass(I2C *connection) {
    i2c = connection;

    //Modo de medida continua (despertar)
    if(i2c->write8(COMPASS_I2C_ADDRESS,0x02,0x00)<0) report(ERROR, "Compass connection failed (not waking up)");
}

Compass::~Compass() {
    report("Disconnecting compass...");
    delete i2c;
    i2c = 0;
    report(OK, "compass disconnected");
}

int Compass::getCompass() {
    return (i2c->read8(COMPASS_I2C_ADDRESS,0x02) << 8) | i2c->read8(COMPASS_I2C_ADDRESS,0x02);
}
