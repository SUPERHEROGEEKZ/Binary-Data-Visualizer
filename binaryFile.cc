/*                                                                                                                                                    
 * Filename:            binaryFile.cc                                                                                                                 
 * Date:                11/25/2020                                                                                                                    
 * Author:              Zainab Anwar
 * Email:               zxa180005@utdallas.edu                                                                                                        
 * Course CS 3377.002 Fall 2020                                                                                                                      
 * Version:             1.0                                                                                                                           
 * Copyright:           2020, All Rights Reserved                                                                                                     
 *                                                                                                                                                    
 * Description:                                                                                                                                       
 * This class includes the BinaryFileHeader class which is used in Main
 * 
 */
#include "header.h"
//BinaryFileHeader in a separate source file but still being used in Main
class BinaryFileHeader
{
public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};
