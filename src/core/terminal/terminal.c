/**
 * \file terminal.c
 * 
 * \author wil.tor
 * 
 * \date 31/10/2018
 *
 * \version 1.0
 *
 * \brief All functions for write and read in terminal. 
 *
 * \details Write in VGA's buffer.
 */

#include "../../libk/includes/stdint.h" /* All integerer types */ 
#include "../../libk/includes/string.h" /* For strcpy function */

#include "terminal.h" /* Header file */ 

/**********************************************************************
 * ENUMERATIONS
 *********************************************************************/

 /**********************************************************************
 * GLOBAL VARIABLES
 *********************************************************************/

/**********************************************************************
 * FUNCTIONS
 *********************************************************************/

inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}

void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	// terminal_color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (uint16_t y = 0; y < VGA_HEIGHT; y++) {
		for (uint16_t x = 0; x < VGA_WIDTH; x++) {
			const uint16_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, uint16_t x, uint16_t y) 
{
	const uint16_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) 
{
	if(c==(int)'\n')
	{
		terminal_row++;
		terminal_column = 0;
	}
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

void terminal_write(const char* data, uint16_t size) 
{
	for (uint16_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data, uint8_t fg) 
{
	fg != (0) ? terminal_setcolor(fg) : 0;
	terminal_write(data, kstrlen(data));
}

void terminal_clear(void)
{
	terminal_row ^= terminal_row;
	terminal_column ^= terminal_column;
}