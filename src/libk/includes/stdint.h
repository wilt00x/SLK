/**
 * \file stdint.h
 * 
 * \author wil.tor
 * 
 * \date 29/10/2018
 *
 * \version 1.0
 *
 * \brief Kernel's basic types. 
 *
 * \details Define basics int types.
 */


#ifndef STDINT_H
#define STDINT_H

/* Define all integerers types */
/**
 * \brief Define int8_t type as an exact 8-bit value.
 */
typedef signed char				int8_t;
/**
 * \brief Define uint8_t type as an exact 8-bit value.
 */
typedef unsigned char 			uint8_t;
/** 
 * \brief Define int16_t type as an exact 16-bit value.
 */
typedef signed short 			int16_t;
/**
 * \brief Define uint16_t type as an exact 16-bit value.
 */
typedef unsigned short 			uint16_t;
/**
 * \brief Define int32_t type as an exact 32-bit value.
 */
typedef signed int 				int32_t;
/**
 * \brief Define uint32_t type as an exact 32-bit value.
 */
typedef unsigned int 			uint32_t;
/** 
 * \brief Define int64_t type as an exact 64-bit value.
 */
typedef signed long long 		int64_t;
/**
 * \brief Define uint64_t type as an exact 64-bit value.
 */
typedef unsigned long long 		uint64_t;

/* Define all minimum value for all int types */ 
/** \brief Define mininmum value for int8_t type. */
#define INT8_MIN			(-128)
/** \brief Define mininmum value for int16_t type. */
#define INT16_MIN			(-32768)
/** \brief Define minimum value for int32_t type. */
#define INT32_MIN			(-2147483648)
/** \brief Define minimum value for int64_t type. */
#define INT64_MIN			(-274877906816)

/* Define all maximum value for all int types */
/** \brief Define maximum value for int8_t type. */
#define INT8_MAX			127
/** \brief Define maximum value for int16_t type. */
#define INT16_MAX			32767
/** \brief Define maximum value for int32_t type. */
#define INT32_MAX			2147483647
/** \brief Define maximum value for int64_t type. */
#define INT64_MAX			274877906815

/* Define all maximum value for all unsigned int types */
/** \brief Define maximum value for uint8_t type */
#define UINT8_MAX			255
/** \brief Define maximum value for uint16_t type. */
#define UINT16_MAX			65535
/** \brief Define maximum value for uint32_t type. */
#define UINT32_MAX			4294967295
/** \brief Define maximum value for uint64_t type. */ 
#define UINT64_MAX			549755813632

#endif /* STDINT_H */