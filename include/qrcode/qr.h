#ifndef __QR_CODE_INCLUDED__
#define __QR_CODE_INCLUDED__


#include "qr_config.h"


struct qr_t;
typedef struct qr_t *QrCode;


QrCode qr_create_from_string(const char *body);
QrCode qr_create_empty();
void qr_destroy(QrCode *qr);


#endif // __QR_CODE_INCLUDED__
