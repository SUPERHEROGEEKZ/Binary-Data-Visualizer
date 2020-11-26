/*                                                                                                                                    
 * Filename:            cdkexample.cc                                                                                                 
 * Date:                11/25/2020                                                                                                    
 * Author:              Zainab Anwar with help from Professor Stephen Perkins' cdkexample
 * Email:               zxa180005@utdallas.edu                                                                                  
 * Course CS 3377.002 Fall 2020                                                                                                                      
 * Version:             1.0                                                                                                           
 * Copyright:           2020, All Rights Reserved                                                                                     
 *                                                                                                                                    
 * Description:                                                                                                                       
 *                                                                                                                                    
 *      Build and display a small text based GUI matrix using curses                                                                  
 *      and the CDK.                                                                                                                  
 */

#include "header.h"
#include "binaryFile.cc"

/*                                                                                                                                    
 * For grins and giggles, we will define values using the C                                                                           
 * Preprocessor instead of C or C++ data types.  These symbols (and                                                                   
 * their values) get inserted into the Preprocessor's symbol table.                                                                   
 * The names are replaced by their values when seen later in the code.                                                                
 */

#define MATRIX_ROWS 5
#define MATRIX_COLS 3
#define BOX_WIDTH 18 //15
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int main()
{
  BinaryFileHeader *header = new BinaryFileHeader();

  ifstream binInFile("/scratch/perkins/cs3377.bin", ios::in | ios::binary);

  if(!binInFile.is_open())
    {
      cerr << "ERROR: Could not open file!" << endl;
      exit(EXIT_FAILURE);
    }

  binInFile.read((char *)header, sizeof(BinaryFileHeader));
  
  stringstream magic;
  magic << hex << uppercase << header->magicNumber;
  string magicToStr = magic.str();
  string magicToStr2 = "0x" + magicToStr;
  string magicToStr3 = "Magic: " + magicToStr2;
  
  stringstream version;
  version << header->versionNumber;
  string versionToStr = version.str();
  string versionToStr2 = "Version: " + versionToStr;

  stringstream record;
  record << header->numRecords;
  string recordToStr = record.str();
  string recordToStr2 = "NumRecords: " + recordToStr;
  
  int recordsNum = header->numRecords; 
  BinaryFileRecord record1[recordsNum]; 
  for (int i = 0; i < recordsNum; i++)
    {
      binInFile.read((char*) &record1[i],sizeof(BinaryFileRecord)); 
    }
  int buflen00 = strlen(record1[0].stringBuffer);
  string buflen02 = to_string(buflen00);
  string buflen03 = "strlen: " + buflen02;

  int buflen11 = strlen(record1[1].stringBuffer);
  string buflen12 = to_string(buflen11);
  string buflen13 = "strlen: " + buflen12;

  int buflen22 = strlen(record1[2].stringBuffer);
  string buflen022 = to_string(buflen22);
  string buflen23 = "strlen: " + buflen022;

  int buflen33 = strlen(record1[3].stringBuffer);
  string buflen32 = to_string(buflen33);
  string buflen033 = "strlen: " + buflen32;

  /*
  int recordsNum;
  recordsNum = header->numRecords; 
  BinaryFileRecord *record[recordsNum];
  for (int i = 0; i < recordsNum; i++)
    { 
      binInFile.read((char*)record, sizeof(BinaryFileRecord)); 
    }
  */
  /*
  char magic[maxRecordStringLength];
  sprintf(magic, "Magic: 0x%X", header->magicNumber);

  char version[maxRecordStringLength];
  sprintf(version, "Version: %u", header->versionNumber);

  char record[maxRecordStringLength];
  sprintf(record, "NumRecords: %lu", header->numRecords);
  */

  binInFile.close();

  WINDOW        *window;
  CDKSCREEN     *cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix                                                                             
               
  // CDK uses offset 1 and C/C++ use offset 0.  Therefore, we create one more                                                         
  // slot than necessary and ignore the value at location 0.                                                                          
               
                    
  const char            *rowTitles[MATRIX_ROWS+1] = {"IGNORE", "a", "b", "c", "d", "e"};
  const char            *columnTitles[MATRIX_COLS+1] = {"IGNORE", "a", "b", "c"};
  int           colWidths[MATRIX_COLS+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int           boxTypes[MATRIX_COLS+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*                                                                                                                                  
   * Initialize the Cdk screen.                                                                                                       
   *                                                                                                                                  
   * Make sure the putty terminal is large enough                                                                                     
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*                                                                                                                                  
   * Create the matrix.  Need to manually cast (const char**) to (char **)                                                            
   */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_ROWS, MATRIX_COLS, MATRIX_ROWS, MATRIX_COLS,
                          MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, colWidths,
			  boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*                                                                                                                                  
   * Dipslay a message                                                                                                                
   */
  setCDKMatrixCell(myMatrix, 1, 1, magicToStr3.c_str());
  setCDKMatrixCell(myMatrix, 1, 2, versionToStr2.c_str());
  setCDKMatrixCell(myMatrix, 1, 3, recordToStr2.c_str());
  setCDKMatrixCell(myMatrix, 2, 1, buflen03.c_str());
  setCDKMatrixCell(myMatrix, 2, 2, record1[0].stringBuffer);
  setCDKMatrixCell(myMatrix, 3, 1, buflen13.c_str());
  setCDKMatrixCell(myMatrix, 3, 2, record1[1].stringBuffer);
  setCDKMatrixCell(myMatrix, 4, 1, buflen23.c_str());
  setCDKMatrixCell(myMatrix, 4, 2, record1[2].stringBuffer);
  setCDKMatrixCell(myMatrix, 5, 1, buflen033.c_str());
  setCDKMatrixCell(myMatrix, 5, 2, record1[3].stringBuffer);

  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (10);


  // Cleanup screen                                                                                                                   
               
                    
  endCDK();
}
