/*
 * i2c.cpp
 *
 *  Created on: Jul 8, 2013
 *  Original author: mike
 *
 *  Customized on Jul 2, 2014
 *  Secondary author: JavierIH
 *
 */

#include "i2c.h"

I2C::I2C(int bus) {
	file = 0;
	this->bus = bus;
}

I2C::~I2C() {
    close(file);
}


bool I2C::test(__u16 address){
    if(!this->openConnection(address)) return 0;
    else if(!this->closeConnection()) return 0;
    else return 1;
}

bool I2C::openConnection(__u16 address) {
	snprintf(filename, 19, "/dev/i2c-%d", bus);
	file = open(filename, O_RDWR);
	if (file < 0) {
        report(WARNING,"I2C openConnection FAILED 1");
		return false;
	}

	if (ioctl(file, I2C_SLAVE, address) < 0) {
        report(WARNING,"I2C openConnection FAILED 2");
		return false;
	}

	return true;
}

bool I2C::closeConnection() {
	if(close(file) < 0) return false;
	return true;
}

__s32 I2C::read8(__u16 address,__u8 reg) {
	// Read a byte
    this->openConnection(address);

	__s32 result;
	result = i2c_smbus_read_byte_data(file, reg);
	if (result < 0) {
        report(WARNING,"in I2C read (read8) operation");
    }

	this->closeConnection();
	return result;
}

int I2C::write8(__u16 address,__u8 reg, __u8 data) {
	// Write a byte
    this->openConnection(address);

	__s32 result;
	result = i2c_smbus_write_byte_data(file, reg, data);
	if (result < 0) {
        report(WARNING,"in I2C write (write8) operation");
    }

	this->closeConnection();
	return result;
}

int I2C::read16(__u16 address,__u8 reg) {
	// Read a word
    this->openConnection(address);

	__s32 result;
	result = i2c_smbus_read_word_data(file, reg);
	if (result < 0) {
        report(WARNING,"in I2C read (read16) operation");
    }

	this->closeConnection();
	return result;
}

int I2C::write16(__u16 address,__u8 reg, __u16 data) {
	// Write a word
    this->openConnection(address);

	__s32 result;
	result = i2c_smbus_write_byte_data(file, reg, data);
	if (result < 0) {
        report(WARNING,"in I2C write (write16) operation");
    }

	this->closeConnection();
	return result;
}
