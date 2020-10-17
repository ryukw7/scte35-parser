#include <catch2/catch.hpp>
#include "../lib/scte35_types.h"

TEST_CASE("ParseSCTE35FromByteArray.scte35_1") {
    FILE *fp = fopen("../../test/cases/scte35_1.bin", "rb");
    splice_info_section_struct_list_t *splice_info_section_list = nullptr;
    ParseSCTE35FromByteArray(fp, &splice_info_section_list);
    fclose(fp);
}