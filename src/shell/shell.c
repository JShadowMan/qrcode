#include <stdio.h>
#include "qrcode/qr.h"


int main(int argc, char *argv[]) {
    QrCode qr = qrCreateFromString("QrCode");
    qrSetErrorDetectionLevel(qr, QR_ERROR_DETECTION_LEVEL_HIGH);

    printf("QrCode[size=%d, value=%p]\n", sizeof(qr), qr);

    qrDestroy(&qr);
    printf("QrCode[size=%d, value=%p]\n", sizeof(qr), qr);

    return 0;
}
