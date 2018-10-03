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


// qr data
struct qr_t;
typedef struct qr_t *QrCode;


QrCode qr_create_from_string(const char *body);
QrCode qr_create_from_empty();

void qr_set_body(QrCode qr, const char *body);
void qr_set_error_detection_level(QrCode qr, QrCodeErrorDetectionLevel level);

void qr_destroy(QrCode *qr);


#endif // __QR_CODE_INCLUDED__
