/**
 * \file global_descriptor_table_management.h
 * 
 * \author wil.tor
 * 
 * \date 31/10/2018
 *
 * \version 1.0
 *
 * \brief Initialize Global Descriptor Table. 
 */

#include "../../libk/includes/stdint.h" /* All integerer types */

#ifndef GLOBAL_DESCRIPTOR_TABLE_MANAGEMENT_H
#define GLOBAL_DESCRIPTOR_TABLE_MANAGEMENT_H

/**********************************************************************
 * STRUCTURES
 *********************************************************************/

/** 
 * \brief Define a structure containing all the elements of a gdt entry.
 */
struct global_descriptor_table_entry_descriptor
{
	/**
	 * \brief The content of bits 0 to 15 of the limit's value.
	 */
	uint16_t lim0_15;

	/**
	 * \brief A 32-bit address containing where the segment begins.
	 */
	uint16_t base0_15;


	/**
	 * \brief The content of bits 16 to 19 of the limit's value.
	 */
	uint8_t lim16_19: 4;

	/** 
	 * \brief The content of bits 24 to 31 of the base's value.
	 */
	uint8_t base24_31;

	/** 
	 * \brief The content of bits 16 to 23 of the base's value.
	 */
	uint8_t base16_23;

	uint8_t access_byte;

	uint8_t flags: 4;
} __attribute__((packed));
typedef struct global_descriptor_table_entry_description gdt_desc;

struct global_descriptor_table_descriptor
{
	/** 
	 * \brief The size of the decremented table.
	 *
	 * \details The maximum size is 4294967295. 536870912 entries possible for gdt.
	 */
	uint32_t base; 

	/** 
	 * \brief Limit is the linear address of Global Descriptor Table.
	 */
	uint16_t limit;
} __attribute__((packed));
typedef struct global_descriptor_table_descriptor gdtr;

/**********************************************************************
 * FUNCTIONS
 *********************************************************************/

void initialize_gdt_descriptor(uint32_t base, uint16_t limit, uint16_t flag);

#endif /* GLOBAL_DESCRIPTOR_TABLE_MANAGEMENT_H */
