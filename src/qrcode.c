#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

#include "qrcode/qrcode.h"


//
// Qrcode structure definition
//
struct qrcode_t {

    // value of is micro symbol
    uint8_t micro           : 1;

    // version value from 1 to 40
    uint8_t version         : 6;

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


//
// Encodable character set
//
// 1. Numeric (digits only)
//      0 1 2 3 4 5 6 7 8 9
// 2. Alphanumeric (digits, UPPER case letters, nine other characters)
//      0 1 2 3 4 5 6 7 8
//      A B C D E F G H I J I K L M N O P Q R S T U V W X Y Z
//      $ % * + - . / : [SPACE]
// 3. Byte (Octet mode)
// 4. Kanji character (can be compacted into 13bits)
//


//
// Timing pattern
//
// The horizontal and vertical timing patterns respectively consist of
// a one row or column of alternating dark and light modules, commencing
// and ending with a dark module.
//
