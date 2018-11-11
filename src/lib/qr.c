#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "qrcode/qr.h"
#include "qrcode/qr_matrix.h"


// encoding mode
enum qr_encoding_mode_t {
    QR_ENCODING_NUMERIC                 = 0x01,  // Max. 7,089 characters
    QR_ENCODING_ALPHANUMERIC            = 0x02,  // Max. 4,296 characters
    QR_ENCODING_BINARY                  = 0x04,  // Max. 2,953 characters
    QR_ENCODING_KANJI                   = 0x08   // Max. 1,817 characters
};
typedef enum qr_encoding_mode_t QrCodeEncodingMode;


struct qr_t {
    uint8_t version                     : 8;
    uint8_t moduleSize                  : 8;
    uint8_t encodingMode                : 4;
    uint8_t errorDetectionLevel         : 4;

    const char *body;
    QrMatrix matrix;
};


static void qrVersionUpdate(QrCode qr);


/**
 *
 */
QrCode qrCreateFromString(const char *body) {
    QrCode qr = qrCreateFromEmpty();
    qrSetBody(qr, body);

    return qr;
}

/**
 *
 */
QrCode qrCreateFromEmpty() {
    QrCode qr = (QrCode)malloc(sizeof(struct qr_t));
    memset(qr, 0, sizeof(struct qr_t));

    qr->errorDetectionLevel = QR_ERROR_DETECTION_LEVEL_MEDIUM;

    return qr;
}

void qrSetBody(QrCode qr, const char *body) {
    qr->body = body;
    qrVersionUpdate(qr);
}

void qrSetErrorDetectionLevel(QrCode qr, QrCodeErrorDetectionLevel level) {
    qr->errorDetectionLevel = level;
}

void qrDestroy(QrCode *qr) {
    if ((*qr)->matrix) {
        free((*qr)->matrix);
    }

    free(*qr);
    *qr = NULL;
}


static void qrVersionUpdate(QrCode qr) {
    qr->version = 1;
}
