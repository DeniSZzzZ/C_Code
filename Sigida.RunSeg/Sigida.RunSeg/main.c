/*
 * Sigida.RunSeg.c
 * Created: 11-Feb-20 10:13:24 PM
 * Author : Denis
 */ 


#include <avr/io.h>
#include <util/delay.h>

#define TIME 50
#define F_CPU 800000UL


//Основаня программа 
int main(void)
{
	PORTB=0x00;
	DDRB=0xFF;
	PORTD=0xFF;
	DDRD=0x00;
    while (1) 
    {

		//Проверяем PORTB если на первом пине true, тогда поочередно
		//выводит элементы массива в котором лежат двоичный код 
		//зажигания каждого сегмента по отдельности, если отжата то 
		//выводим в обратном направлении 
		
		//Если кнопка нажата
		if ((PIND&0x01)==0)
			{
				_delay_ms(100);
				char runCode [] = {0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b00000001};
				for (char i=0;i<=7;i++)
				{
					PORTB=runCode[i];
					_delay_ms(TIME);
				}
		}//Если кнопка отжата
		else
		{
			_delay_ms(100);
			char runCode [] = {0b00000001,0b00100000,0b00010000,0b00001000,0b00000100,0b00000010,0b00000001};
			for (char i=0;i<=7;i++)
			{
				PORTB=runCode[i];
				_delay_ms(TIME);
			}
		}		
    }
	
	return 0;
}

