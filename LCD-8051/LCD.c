#include <reg51.h>
sbit rs = P1^0;
sbit rw = P1^1;
sbit en = P1^2;

void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_init();
void delay_ms(unsigned int ms);

void delay_ms(unsigned int ms)
{
	unsigned int i,j;
	for(i=0; i< ms; i++)
		for(j=0; j< 127; j++);
}

void lcd_cmd(unsigned char cmd)
{
	P2=cmd;
	rs=0; rw=0; 
	en=1; delay_ms(2); en=0;
}

void lcd_data(unsigned char dat)
{
	P2=dat;
	rs=1; rw=0;
	en=1; delay_ms(2); en=0;
}

void lcd_init()
{
	lcd_cmd(0x38); // 8-bit mode, 2- line, 5x7 dots
	lcd_cmd(0x0C); // Display on, Cursor off
	lcd_cmd(0x01); // clear display
	lcd_cmd(0x80); // Move cursor to beginning (line1)
}

void main()
{
	char name[]= "GAJENDRA Saksham Aakarsh";
	unsigned int i;
	lcd_init();
	while(1)
	{
		i=0;
		lcd_cmd(0x01);
		lcd_cmd(0x80); // Move to line 1
		while (name[i] != '\0')
		{
			if(i==16)
			{ lcd_cmd(0xC0); } // if 16 characters are done , move to line 2
			lcd_data(name[i]);
			delay_ms(300);
			i++;
		}
		delay_ms(2000);
	}
}


