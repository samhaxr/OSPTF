/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#ifndef HEADER_RAND_H
#define HEADER_RAND_H

#include <stdint.h>
#include <stdlib.h>

#include <openssl/base.h>

#ifdef __cplusplus
extern "C" {
#endif

struct rand_meth_st {
    void (*seed)(const void *buf, int num);
    int (*bytes)(uint8_t *buf, int num);
    void (*cleanup)(void);
    void (*add)(const void *buf, int num, double entropy);
    int (*pseudorand)(uint8_t *buf, int num);
    int (*status)(void);
};

#ifdef BN_DEBUG
extern int rand_predictable;
#endif

VIGORTLS_EXPORT int RAND_set_rand_method(const RAND_METHOD *meth);
VIGORTLS_EXPORT const RAND_METHOD *RAND_get_rand_method(void);
#ifndef OPENSSL_NO_ENGINE
VIGORTLS_EXPORT int RAND_set_rand_engine(ENGINE *engine);
#endif
VIGORTLS_EXPORT RAND_METHOD *RAND_SSLeay(void);
VIGORTLS_EXPORT void RAND_cleanup(void);
VIGORTLS_EXPORT int RAND_bytes(uint8_t *buf, size_t len);
VIGORTLS_EXPORT int RAND_pseudo_bytes(uint8_t *buf, size_t len);
VIGORTLS_EXPORT void RAND_seed(const void *buf, int num);
VIGORTLS_EXPORT void RAND_add(const void *buf, int num, double entropy);
VIGORTLS_EXPORT int RAND_load_file(const char *file, long max_bytes);
VIGORTLS_EXPORT int RAND_write_file(const char *file);
VIGORTLS_EXPORT const char *RAND_file_name(char *file, size_t num);
VIGORTLS_EXPORT int RAND_status(void);
VIGORTLS_EXPORT int RAND_query_egd_bytes(const char *path, uint8_t *buf,
                                         int bytes);
VIGORTLS_EXPORT int RAND_egd(const char *path);
VIGORTLS_EXPORT int RAND_egd_bytes(const char *path, int bytes);
VIGORTLS_EXPORT int RAND_poll(void);

/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */
VIGORTLS_EXPORT void ERR_load_RAND_strings(void);

/* Error codes for the RAND functions. */

/* Function codes. */
# define RAND_F_RAND_GET_RAND_METHOD                      101
# define RAND_F_SSLEAY_RAND_BYTES                         100

/* Reason codes. */
# define RAND_R_DUAL_EC_DRBG_DISABLED                     104
# define RAND_R_ERROR_INITIALISING_DRBG                   102
# define RAND_R_ERROR_INSTANTIATING_DRBG                  103
# define RAND_R_PRNG_NOT_SEEDED                           100

#ifdef  __cplusplus
}
#endif
#endif
