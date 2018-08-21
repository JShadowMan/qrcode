#include <stdio.h>
#include "qrcode/qr.h"


int main(int argc, char *argv[]) {
    QrCode qr = qr_create_from_string("QrCode");
    printf("QrCode[size=%d, value=%p]\n", sizeof(qr), qr);

    qr_destroy(&qr);
    printf("QrCode[size=%d, value=%p]\n", sizeof(qr), qr);

    return 0;
}
