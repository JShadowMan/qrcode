#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <qrcode/qr.h>

#include "qrcode/qr.h"
#include "qrcode/qr_matrix.h"


struct qr_t {
    uint8_t version;
    const char *body;
    QrMatrix matrix;
};


QrCode qr_create_from_string(const char *body) {
    return qr_create_empty();
}

QrCode qr_create_empty() {
    QrCode qr = (QrCode)malloc(sizeof(struct qr_t));
    memset(qr, 0, sizeof(struct qr_t));

    return qr;
}

void qr_destroy(QrCode *qr) {
    free(*qr);
    *qr = NULL;
}
