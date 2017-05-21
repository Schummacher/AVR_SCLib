/*
 * I2C.c
 *
 * Created: 2016/9/22 12:32:55
 *  Author: dusch
 */ 

#include "I2C.h"

 /******** TWI接口的初始化函数********/
void I2C_Init(void)
{
	TWAR = 0x00;         	//主机模式，该地址无效
	TWCR = 0x00;         	//关闭TWI模块
	TWBR = 100;        //100
	TWSR = 0x03;         //64分频
 }
 /********将Write_data写入AT24C04内部的以EE_address为地址的存储区********/
void I2C_Write(unsigned char Write_data, unsigned char EE_address)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));  //0x08
	TWDR = SLA_W;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));  //0x18
	TWDR = EE_address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));  //0x28
	TWDR = Write_data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));  //0x28
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}
/********从AT24C04内部的以EE_address为地址的存储区读出数据********/
unsigned char I2C_Read(unsigned char EE_address)
{
	unsigned char temp;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));
	TWDR = SLA_W;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	TWDR = EE_address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(!(TWCR & (1<<TWINT)));
	TWDR = SLA_R;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	temp = TWDR;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	return temp;
}