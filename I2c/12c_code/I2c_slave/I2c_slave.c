#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
void TWI_inti(unsigned char slave_addr)
{
	TWAR=slave_addr;
}
unsigned char TWI_Read_data()
{unsigned char x;
	TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	while((TWSR&(0xf8))!=0x80);
x=TWDR;
return x;
}
void TWI_Match_ACK()
{
	while ((TWSR&(0xf8))!=0x60)
	{
		TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
		while((TWCR&(1<<TWINT))==0);
	}
}
int main(void)
{
	DDRB=0xff;
	TWI_inti(0x20);
    while(1)
    {
		TWI_Match_ACK();
 PORTB=TWI_Read_data();
 //_delay_ms(1000);
    }
} 