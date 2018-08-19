#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrcode/qrcode.h"


struct _qr_code_struct {
    const char *body;
};
typedef struct _qr_code_struct QrCode;


QrCode *qc_create_from_string(const char *body) {
    QrCode *qc = qc_create_empty();
    return qc;
}

QrCode *qc_create_empty() {
    QrCode *qc = (QrCode*)malloc(sizeof(QrCode));
    return qc;
}
