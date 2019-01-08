#ifndef __QRCODE_QRCODE_INCLUDED__
#define __QRCODE_QRCODE_INCLUDED__

#include "qr_config.h"


struct qrcode_t;
typedef struct qrcode_t* Qrcode;


Qrcode createQrcodeFromString(char *string);
void destroyQrcode(Qrcode *qrcode);


#endif // __QRCODE_QRCODE_INCLUDED__
