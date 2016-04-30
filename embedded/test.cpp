
#include <stdio.h>
#include <string.h>

void AddNMEATTail(unsigned char *msg)
{
 unsigned char Checksum;
 unsigned int Pos;
 unsigned  char TempStr[6];

 Checksum = 0;
 for ( Pos=1; msg[Pos]; Checksum ^= msg[Pos++] )
 {
  ;
 }
 sprintf( (char*)TempStr, "*%02X\r\n", Checksum );
 strcat( (char*)msg, (const char*)TempStr );
}

int main(void)
{
 unsigned char string[]="abcd\0efg\0\0\0\0\0\0";

 AddNMEATTail(string);
 printf((const char*)string);
 return 0;
}
