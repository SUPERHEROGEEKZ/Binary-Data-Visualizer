#include "header.h"
//BinaryFileHeader in a separate source file but still being used in Main
class BinaryFileHeader
{
public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};
