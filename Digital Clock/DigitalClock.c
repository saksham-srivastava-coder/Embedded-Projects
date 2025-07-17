#include <reg51.h>
sbit seg1 = P1^0; // common anode connections of 7 segment display with 8051
sbit seg2 = P1^1;
sbit seg3 = P1^2;
sbit seg4 = P1^3; 
sbit seg5 = P1^4;
sbit seg6 = P1^5;

void delay_ms(unsigned int ms)
{
	unsigned int i,j;
	for (i = 0; i < ms; i++)
		for (j = 0; j < 127; j++);
}

unsigned char seg_val[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void display_digit(unsigned char seg, unsigned char val)
{
	seg1=seg2=seg3=seg4=seg5=seg6=0;
	if(seg==1) seg1=1;
	else if(seg==2) seg2=1;
	else if(seg==3) seg3=1;
	else if(seg==4) seg4=1;
	else if(seg==5) seg5=1;
	else if(seg==6) seg6=1;
	P2=seg_val[val];
	delay_ms(2);
}

unsigned char minutes=0;
unsigned char seconds=0;
unsigned char hours=0;

void refresh_display(unsigned char h, unsigned char m, unsigned char s)
{
	unsigned int i;
	for(i = 0; i < 83; i++) // for taking only 1 second
	{
		display_digit(1,h/10);
		display_digit(2,h%10);
		display_digit(3,m/10);
		display_digit(4,m%10);
		display_digit(5,s/10);
		display_digit(6,s%10);
	}
}
		
void main ()
{
	while(1)
	{
		refresh_display(hours,minutes,seconds);
		seconds++;
		if(seconds>=60)
		{
			seconds=0;
			minutes++;
			if(minutes>=60)
			{
				minutes=0;
				hours++;
				if(hours>=24)
					hours=0;
			}
		}
	}
}
			