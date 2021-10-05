#include <stdio.h>
#include<conio.h>

typedef struct {
	char source[10];
	int id;
	unsigned long timestamp;
	int temperature;
	int humidity;
	int pressure;
} measurement_t;

measurement_t measurements;


void serializeInt(char *myByteArray, int value, int&iterator)
{
	int shifter = 3;
	while (shifter >= 0)
	{
		myByteArray[iterator] = (value >> shifter * 8) & 0xff;
		++iterator;
		--shifter;
	}
}

int main() {

	//test values
	measurements.id = 9876;
	measurements.timestamp = 997543;
	measurements.temperature = 37;
	measurements.pressure = 1200;
	for(int i=0;i<10;i++)
		measurements.source[i] = 128-i;
	
	//in order to not dynamically allocate stuff i will conider sizes as constant values
	//eventually a define can be used for the char[SIZE] in order to change in both the structure
	//and serialization if needed afterwards

	char myByteArray[30];
	int iterator = 0;
	for (int i = 0; i < 10; i++)
	{
		myByteArray[iterator] = measurements.source[i];
		++iterator;
	}

	serializeInt(myByteArray, measurements.id, iterator);
	serializeInt(myByteArray, measurements.timestamp, iterator);
	serializeInt(myByteArray, measurements.temperature, iterator);
	serializeInt(myByteArray, measurements.humidity, iterator);
	serializeInt(myByteArray, measurements.pressure, iterator);

	for (int i = 0; i < 30; i++) {
		printf("%c\n",myByteArray[i]);
	}

	_getch();
}