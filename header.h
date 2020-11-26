/*                                                                                                                                                   
 * Filename header.h                                                                                                                                 
 * Date November 25, 2020                                                                                                                            
 * Author Zainab Anwar                                                                                                                               
 * Email zxa180005@utdallas.edu                                                                                                                      
 * Course CS 3377.002 Fall 2020                                                                                                                      
 * Version 1.0                                                                                                                                       
 * Copyright 2020, All Rights Reserved                                                                                                               
 *                                                                                                                                                   
 * Description                                                                                                                                       
 *                                                                                                                                                   
 * This header file contains include statements and function headers so that the functions could be used in any files needed.                        
 */

#ifndef _HEADER_
#define _HEADER_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cdk.h"
#include <cstdint>
/*
class BinaryFileHeader
{
 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};
*/
//function headers
class BinaryFileHeader;

const int maxRecordStringLength = 25;
class BinaryFileRecord
{
 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

#endif
