#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void TWI_inti()
{
	TWBR=0x00;  //clear status reg
	TWBR=0x0c;  //set bit rate
	
}
void TWI_start()
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while((TWCR&(1<<TWINT))==0);
	while((TWSR&(0xf8))!=0x08);
}
void TWI_write_addr(unsigned char addr)
{
	TWDR=addr;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	while((TWSR&(0xf8))!=0x18);
}
void TWI_write_data(unsigned char data)
{
TWDR=data;
TWCR=(1<<TWINT)|(1<<TWEN);
while((TWCR&(1<<TWINT))==0);
while((TWSR&(0xf8))!=0x28);
	
}
void TWI_stop()
{
TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
int main(void)
{TWI_inti();
	
	while(1)
    {
		TWI_start();
		_delay_ms(1000);
		TWI_write_addr(0x20);
		_delay_ms(1000);
		TWI_write_data('A');
		_delay_ms(1000);
		TWI_stop();
		_delay_ms(1000);
    }
}