#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <qrcode/qr.h>


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
    uint8_t module_size                 : 8;
    uint8_t encoding_mode               : 4;
    uint8_t error_detection_level       : 4;

    const char *body;
    QrMatrix matrix;
};


static void qr_update_version_by_body(QrCode qr, const char *body);
static inline uint8_t calc_module_size_by_version(uint8_t version);


QrCode qr_create_from_string(const char *body) {
    QrCode qr = qr_create_from_empty();
    qr_set_body(qr, body);

    return qr;
}

QrCode qr_create_from_empty() {
    QrCode qr = (QrCode)malloc(sizeof(struct qr_t));
    memset(qr, 0, sizeof(struct qr_t));

    qr->error_detection_level = QR_ERROR_DETECTION_LEVEL_MEDIUM;

    return qr;
}

void qr_set_body(QrCode qr, const char *body) {
    qr->body = body;

    qr_update_version_by_body(qr, body);
    qr->module_size = calc_module_size_by_version(qr->version);
}

void qr_set_error_detection_level(QrCode qr, QrCodeErrorDetectionLevel level) {
    qr->error_detection_level = level;
}

void qr_destroy(QrCode *qr) {
    free(*qr);
    *qr = NULL;
}


void qr_update_version_by_body(QrCode qr, const char *body) {
    qr->version = 1;
}

uint8_t calc_module_size_by_version(uint8_t version) {
    return (uint8_t) ((version - 1) * 4 + 21);
}
