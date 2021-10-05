#include "uart_driver.h"
#include <stdio.h>
#include<conio.h>

void print_sensor_data(sensor_data_t *sensor_data);

int main() {
	sensor_data_t sensor_data;
	get_sensor_data(&sensor_data);
	print_sensor_data(&sensor_data);
	_getch();
}

/** the data from the sensor comes in as following:
 * 1. id            [char,  1 bytes]
 * 2. int_data      [int,   4 bytes]
 * 3. short_data    [short, 2 bytes]
 * 4. char_data     [char,  1 bytes]
 */
void get_sensor_data(sensor_data_t *sensor_data) {
	uart_driver_start_communication();

    
	sensor_data->id = uart_driver_get_byte();

	sensor_data->int_data = 0;
	sensor_data->int_data |= uart_driver_get_byte();
	for (int i = 1; i < 4; i++)
	{
		sensor_data->int_data |= (((int)uart_driver_get_byte()) << i * 8);
	}


	sensor_data->short_data = 0;
	sensor_data->short_data |= uart_driver_get_byte();
	for (int i = 1; i < 2; i++)
	{
		sensor_data->short_data;
		sensor_data->short_data |= (((int)uart_driver_get_byte()) << i * 8);
	}

	sensor_data->char_data = uart_driver_get_byte();

	uart_driver_stop_communication();
}

void print_sensor_data(sensor_data_t *sensor_data) {
	printf("id: %d\n", sensor_data->id);
	printf("int_data: %d\n", sensor_data->int_data);
	printf("short_data: %d\n", sensor_data->short_data);
	printf("char_data: %d\n", sensor_data->char_data);
}