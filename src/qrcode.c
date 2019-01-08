#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

#include "qrcode/qrcode.h"


//
// Qrcode structure definition
//
struct qrcode_t {

    // version value from 1 to 40
    uint8_t version;

};


//
// Create an Qrcode instance from a string
//
extern Qrcode createQrcodeFromString(char *string) {
    Qrcode qrcode = (Qrcode)malloc(sizeof(struct qrcode_t));

    // initializing the Qrcode instance
    memset(qrcode, 0, sizeof(struct qrcode_t));

    return qrcode;
}


//
// Destroy an Qrcode instance
//
void destroyQrcode(Qrcode *qrcode) {
    free(*qrcode);
    *qrcode = NULL;
}
