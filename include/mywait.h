/*
MIT License
see LICENSE file
*/

#ifndef _MY_WAIT_H_
#define _MY_WAIT_H_

#include "systick.h"

void wait_us( uint32_t us );
void wait_ms( uint32_t ms );
void wait( float sec );

#endif
