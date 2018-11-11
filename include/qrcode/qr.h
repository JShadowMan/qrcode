#ifndef __QR_CODE_INCLUDED__
#define __QR_CODE_INCLUDED__


#include "qr_config.h"


// error detection level
enum qr_error_detection_level_t {
    QR_ERROR_DETECTION_LEVEL_LOW        = 0x01,  // Low +7%
    QR_ERROR_DETECTION_LEVEL_MEDIUM     = 0x02,  // Medium *15%
    QR_ERROR_DETECTION_LEVEL_QUARTILE   = 0x04,  // Quartile +25% [default]
    QR_ERROR_DETECTION_LEVEL_HIGH       = 0x08   // High + 30%
};
typedef enum qr_error_detection_level_t QrCodeErrorDetectionLevel;


// qrcode type definition
struct qr_t;
typedef struct qr_t *QrCode;


QrCode qrCreateFromEmpty();
QrCode qrCreateFromString(const char *body);

void qrSetBody(QrCode qr, const char *body);
void qrSetErrorDetectionLevel(QrCode qr, QrCodeErrorDetectionLevel level);

void qrDestroy(QrCode *qr);


#endif // __QR_CODE_INCLUDED__
