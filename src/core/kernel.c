/**
 * \file kernel.c
 * 
 * \author wil.tor
 * 
 * \date 31/10/2018
 *
 * \version 1.0
 *
 * \brief Kernel's main file. 
 *
 * \details Write in VGA's buffer.
 */


#include "terminal/terminal.c"
#include "memory/global_descriptor_table_management.h"

/** \fn kmain */
void kmain(void) 
{
	terminal_initialize(); /* Initialize terminal interface */
	terminal_writestring("- SLK - v0.0.1", 5);
	terminal_writestring("\nHello World!", 3);
}