#include <stdio.h>
#include "qrcode/qrcode.h"


int main(int argc, char *argv[]) {
    QrCode *qc = qc_create_from_string("qrcode");
    printf("QrCode Shell, size = %d\n", sizeof(qc));

    return 0;
}
