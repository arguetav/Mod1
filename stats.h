/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


float find_mean(unsigned char * numbers, int size);
int find_maximum(unsigned char *numbers, int size);
int find_minimum(unsigned char *numbers, int size);
void print_array(unsigned char *numbers, int size);
void sort_array(unsigned char * numbers, int size);
float find_median(unsigned char * numbers, int size);
#endif /* __STATS_H__ */
