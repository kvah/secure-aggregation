#ifndef _HOST_H
#define _HOST_H

#include <iostream> 
#include <stdio.h>

unsigned char** host_modelaggregator(unsigned char*** encrypted_accumulator, 
        size_t* accumulator_lengths,
        size_t accumulator_length, 
        unsigned char** encrypted_old_params,
        size_t old_params_length);

#endif 