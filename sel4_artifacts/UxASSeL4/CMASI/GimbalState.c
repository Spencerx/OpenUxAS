
#include "common/struct_defines.h"
#include "common/conv.h"
#include "GimbalState.h"
#include "PayloadState.h"
#include "enums.h"
void lmcp_pp_GimbalState(GimbalState* s) {
    printf("GimbalState{");
    printf("Inherited from PayloadState:\n");
    lmcp_pp_PayloadState(&(s->super));
    printf("pointingmode: ");
    printf("%i", s->pointingmode);
    printf("\n");
    printf("azimuth: ");
    printf("%u",s->azimuth);
    printf("\n");
    printf("elevation: ");
    printf("%u",s->elevation);
    printf("\n");
    printf("rotation: ");
    printf("%u",s->rotation);
    printf("\n");
    printf("}");
}
size_t lmcp_packsize_GimbalState (GimbalState* i) {
    size_t out = 0;
    out += lmcp_packsize_PayloadState(&(i->super));
    out += 4;
    out += sizeof(uint32_t);
    out += sizeof(uint32_t);
    out += sizeof(uint32_t);
    return out;
}
size_t lmcp_pack_GimbalState_header(uint8_t* buf, GimbalState* i) {
    uint8_t* outb = buf;
    if (i == NULL) {
        lmcp_pack_uint8_t(outb, 0);
        return 1;
    }
    outb += lmcp_pack_uint8_t(outb, 1);
    memcpy(outb, "CMASI", 5);
    outb += 5;
    for (size_t j = 5; j < 8; j++, outb++)
        *outb = 0;
    outb += lmcp_pack_uint32_t(outb, 27);
    outb += lmcp_pack_uint16_t(outb, 3);
    return 15;
}
void lmcp_free_GimbalState(GimbalState* out, int out_malloced) {
    if (out == NULL)
        return;
    lmcp_free_PayloadState(&(out->super), 0);
    if (out_malloced == 1) {
        free(out);
    }
}
void lmcp_init_GimbalState (GimbalState** i) {
    if (i == NULL) return;
    (*i) = calloc(1,sizeof(GimbalState));
    ((lmcp_object*)(*i)) -> type = 27;
}
int lmcp_unpack_GimbalState(uint8_t** inb, size_t *size_remain, GimbalState* outp) {
    if (inb == NULL || *inb == NULL) {
        return -1;
    }
    if (size_remain == NULL || *size_remain == 0) {
        return -1;
    }
    GimbalState* out = outp;
    CHECK(lmcp_unpack_PayloadState(inb, size_remain, &(out->super)))
    CHECK(lmcp_unpack_int32_t(inb, size_remain, (int*) &(out->pointingmode)))
    CHECK(lmcp_unpack_uint32_t(inb, size_remain, &(out->azimuth)))
    CHECK(lmcp_unpack_uint32_t(inb, size_remain, &(out->elevation)))
    CHECK(lmcp_unpack_uint32_t(inb, size_remain, &(out->rotation)))
    return 0;
}
size_t lmcp_pack_GimbalState(uint8_t* buf, GimbalState* i) {
    if (i == NULL) return 0;
    uint8_t* outb = buf;
    outb += lmcp_pack_PayloadState(outb, &(i->super));
    outb += lmcp_pack_int32_t(outb, (int) i->pointingmode);
    outb += lmcp_pack_uint32_t(outb, i->azimuth);
    outb += lmcp_pack_uint32_t(outb, i->elevation);
    outb += lmcp_pack_uint32_t(outb, i->rotation);
    return (outb - buf);
}