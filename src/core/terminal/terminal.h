/**
 * \file terminal.h
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

#ifndef TERMINAL_H
#define TERMINAL_H

/**********************************************************************
 * ENUMERATIONS
 *********************************************************************/

/** 
 * \brief Define hardware text mode for console.
 *
 * \details Define programmable 16 color palette of VGA text mode.
 */
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

/**********************************************************************
 * GLOBAL VARIABLES
 *********************************************************************/

const uint8_t VGA_WIDTH = 80;
const uint8_t VGA_HEIGHT = 25;
 
uint8_t 		terminal_row;
uint8_t 		terminal_column;
uint8_t 		terminal_color;
uint16_t* 		terminal_buffer;

/**********************************************************************
 * FUNCTIONS
 *********************************************************************/

/** \brief Give the length of str. */
uint16_t strlen(const char* str);

/**
 * \brief Send a colorful unsigned char.
 * 
 * \param uc The unsigned char ton send in a VGA entry.
 *
 * \param bg The color to apply at character.
 */
uint16_t vga_entry(unsigned char uc, uint8_t color);

/* Functions for VGA memory management */
/**
 * \brief Select the background color and the color of writing.
 * 
 * \param fg The foreground color to apply.
 *
 * \param bg The background color to apply.
 */
uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);

/**
 * \brief Initialize terminal.
 *
 * \details Initialize the properties of termine by accessing the vga buffer 
 * at the 0xB8000 address with a size for 80x25 characters.
 */
void terminal_initialize(void);

/** 
 * \brief Set the terminal color.
 *
 * \param color The color to set at terminal.
 */
void terminal_setcolor(uint8_t color);

/**
 * \brief Write char at an entry of VGA buffer.
 *
 * \details Write char by specifying its dimensions and its color.
 *
 * \param c The char to push.
 *
 * \param color The color to set at char c.
 *
 * \param x The width of char c.
 *
 * \param y The height of char c.
 */
void terminal_putentryat(char c, 
	                     uint8_t color, 
	                     uint16_t x, 
	                     uint16_t y);

/**
 * \brief Write a char without specifying its dimension and color.
 *
 * \param c The char to write in VGA buffer.
 */
void terminal_putchar(char c);

/** 
 * \brief Write a string.
 *
 * \details Write the first 'size' bytes of the strings 'data'.
 *
 * \param data The string to write.
 *
 * \param size The number of bytes of 'data' string to be written.
 */
void terminal_write(const char* data, uint16_t size);

/** \brief Write a string. */
void terminal_writestring(const char* data, uint8_t fg);

/** \brief Clear terminal. */
void terminal_clear(void);

#endif /* TERMINAL_H */