#include <catch2/catch.hpp>
#include "../lib/scte35_types.h"

TEST_CASE("ParseSCTE35FromByteArray.scte35_1") {
    FILE *fp = fopen("../../test/cases/scte35_1.bin", "rb");

    splice_info_section_struct_list_t *siList = nullptr;
    ParseSCTE35FromByteArray(fp, &siList);
    splice_insert_t *si = (splice_insert_t *) siList->splice_info_section->splice_command_ptr;
    REQUIRE(si->splice_immediate_flag == false);

//    PrintParsedSCTE35ToFile(NULL, siList);

    REQUIRE(si->unique_program_id == 7030);
    REQUIRE(si->out_of_network_indicator == true);
    REQUIRE(si->break_duration.duration == 1350000);
    REQUIRE(si->splice_event_id == 821094442);
    REQUIRE(si->splice_event_cancel_indicator == false);

    FreeSpliceInfoList(&siList);
    fclose(fp);
}