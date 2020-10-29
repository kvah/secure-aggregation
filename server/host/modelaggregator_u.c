/*
 *  This file is auto generated by oeedger8r. DO NOT EDIT.
 */
#include "modelaggregator_u.h"

#include <openenclave/edger8r/host.h>

OE_EXTERNC_BEGIN

/**** ECALL function wrappers. ****/

oe_result_t enclave_modelaggregator(
    oe_enclave_t* enclave,
    unsigned char*** encrypted_accumulator,
    size_t* accumulator_lengths,
    size_t accumulator_length,
    unsigned char** encrypted_old_params,
    size_t old_params_length,
    unsigned char*** encrypted_new_params_ptr,
    size_t* new_params_length)
{
    oe_result_t _result = OE_FAILURE;

    /* Marshalling struct. */
    enclave_modelaggregator_args_t _args, *_pargs_in = NULL, *_pargs_out = NULL;

    /* Marshalling buffer and sizes. */
    size_t _input_buffer_size = 0;
    size_t _output_buffer_size = 0;
    size_t _total_buffer_size = 0;
    uint8_t* _buffer = NULL;
    uint8_t* _input_buffer = NULL;
    uint8_t* _output_buffer = NULL;
    size_t _input_buffer_offset = 0;
    size_t _output_buffer_offset = 0;
    size_t _output_bytes_written = 0;

    /* Deep copy buffer. */
    /* No pointers to save for deep copy. */

    /* Fill marshalling struct. */
    memset(&_args, 0, sizeof(_args));
    _args.encrypted_accumulator = (unsigned char***)encrypted_accumulator;
    _args.accumulator_lengths = (size_t*)accumulator_lengths;
    _args.accumulator_length = accumulator_length;
    _args.encrypted_old_params = (unsigned char**)encrypted_old_params;
    _args.old_params_length = old_params_length;
    _args.encrypted_new_params_ptr = (unsigned char***)encrypted_new_params_ptr;
    _args.new_params_length = (size_t*)new_params_length;

    /* Compute input buffer size. Include in and in-out parameters. */
    OE_ADD_SIZE(_input_buffer_size, sizeof(enclave_modelaggregator_args_t));
    if (encrypted_accumulator)
        OE_ADD_SIZE(_input_buffer_size, ((size_t)_args.accumulator_length * sizeof(unsigned char**)));
    if (accumulator_lengths)
        OE_ADD_SIZE(_input_buffer_size, ((size_t)_args.accumulator_length * sizeof(size_t)));
    if (encrypted_old_params)
        OE_ADD_SIZE(_input_buffer_size, ((size_t)3 * sizeof(unsigned char*)));
    
    /* Compute output buffer size. Include out and in-out parameters. */
    OE_ADD_SIZE(_output_buffer_size, sizeof(enclave_modelaggregator_args_t));
    if (encrypted_new_params_ptr)
        OE_ADD_SIZE(_output_buffer_size, sizeof(unsigned char**));
    if (new_params_length)
        OE_ADD_SIZE(_output_buffer_size, sizeof(size_t));
    
    /* Allocate marshalling buffer. */
    _total_buffer_size = _input_buffer_size;
    OE_ADD_SIZE(_total_buffer_size, _output_buffer_size);
    _buffer = (uint8_t*)oe_malloc(_total_buffer_size);
    _input_buffer = _buffer;
    _output_buffer = _buffer + _input_buffer_size;
    if (_buffer == NULL)
    {
        _result = OE_OUT_OF_MEMORY;
        goto done;
    }
    
    /* Serialize buffer inputs (in and in-out parameters). */
    _pargs_in = (enclave_modelaggregator_args_t*)_input_buffer;
    OE_ADD_SIZE(_input_buffer_offset, sizeof(*_pargs_in));
    if (encrypted_accumulator)
        OE_WRITE_IN_PARAM(encrypted_accumulator, ((size_t)_args.accumulator_length * sizeof(unsigned char**)), unsigned char***);
    if (accumulator_lengths)
        OE_WRITE_IN_PARAM(accumulator_lengths, ((size_t)_args.accumulator_length * sizeof(size_t)), size_t*);
    if (encrypted_old_params)
        OE_WRITE_IN_PARAM(encrypted_old_params, ((size_t)3 * sizeof(unsigned char*)), unsigned char**);
    
    /* Copy args structure (now filled) to input buffer. */
    memcpy(_pargs_in, &_args, sizeof(*_pargs_in));

    /* Call enclave function. */
    if ((_result = oe_call_enclave_function(
             enclave,
             modelaggregator_fcn_id_enclave_modelaggregator,
             _input_buffer,
             _input_buffer_size,
             _output_buffer,
             _output_buffer_size,
             &_output_bytes_written)) != OE_OK)
        goto done;

    /* Setup output arg struct pointer. */
    _pargs_out = (enclave_modelaggregator_args_t*)_output_buffer;
    OE_ADD_SIZE(_output_buffer_offset, sizeof(*_pargs_out));
    
    /* Check if the call succeeded. */
    if ((_result = _pargs_out->_result) != OE_OK)
        goto done;
    
    /* Currently exactly _output_buffer_size bytes must be written. */
    if (_output_bytes_written != _output_buffer_size)
    {
        _result = OE_FAILURE;
        goto done;
    }
    
    /* Unmarshal return value and out, in-out parameters. */
    /* No return value. */
    /* No pointers to restore for deep copy. */
    OE_READ_OUT_PARAM(encrypted_new_params_ptr, (size_t)(sizeof(unsigned char**)));
    OE_READ_OUT_PARAM(new_params_length, (size_t)(sizeof(size_t)));

    _result = OE_OK;

done:
    if (_buffer)
        free(_buffer);

    /* No `_ptrs` to free for deep copy. */

    return _result;
}

/**** OCALL functions. ****/

/* There were no ocalls. */
/**** OCALL function table. ****/

static oe_ocall_func_t __modelaggregator_ocall_function_table[] = {
    
    NULL
};

oe_result_t oe_create_modelaggregator_enclave(
    const char* path,
    oe_enclave_type_t type,
    uint32_t flags,
    const oe_enclave_setting_t* settings,
    uint32_t setting_count,
    oe_enclave_t** enclave)
{
    return oe_create_enclave(
               path,
               type,
               flags,
               settings,
               setting_count,
               __modelaggregator_ocall_function_table,
               0,
               enclave);
}

OE_EXTERNC_END
