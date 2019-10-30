#ifndef __PRIMALITY_CHECK_H__
#define __PRIMALITY_CHECK_H__

#define PRIME 1;  // ËØÊý
#define COMPOSITE 0 ; // ºÏÊý

bool Primality(unsigned __int64 N);
bool MillerRabin(unsigned __int64 N);
bool Witness(__int64 a, __int64 n);

#endif