#ifndef __QR_CODE_INCLUDED__
#define __QR_CODE_INCLUDED__


#include "qc_config.h"


struct _qr_code_struct;
typedef struct _qr_code_struct QrCode;


QrCode *qc_create_from_string(const char *body);
QrCode *qc_create_empty();


#endif // __QR_CODE_INCLUDED__
