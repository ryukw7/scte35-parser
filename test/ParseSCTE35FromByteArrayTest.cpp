#include <catch2/catch.hpp>
#include "../lib/scte35_types.h"

#include <cstdio>

#include <iostream>

TEST_CASE("ParseSCTE35FromByteArray.scte35_1") {
    FILE *fp = fopen("../../test/cases/scte35_1.bin", "rb");

    splice_info_section_struct_list_t *siList = nullptr;
    ParseSCTE35FromByteArray(fp, &siList);

    FILE *fp2 = fopen("/tmp/x.scte35", "w");
    PrintParsedSCTE35ToFile(fp2, siList);
    fclose(fp2);

    splice_insert_t *si = (splice_insert_t *) siList->splice_info_section->splice_command_ptr;
    REQUIRE(si->splice_immediate_flag == false);

//    REQUIRE(si->splice_time.pts_time == 4599504262L); // 4599504262
    REQUIRE(si->splice_time.pts_time - siList->next->splice_info_section->pts_adjustment - 1 == 4599504262);

    REQUIRE(si->unique_program_id == 7030);
    REQUIRE(si->out_of_network_indicator == true);
    REQUIRE(si->break_duration.duration / 90 == 15000); // 15s
    REQUIRE(si->splice_event_id == 821094442);
    REQUIRE(si->splice_event_cancel_indicator == false);

    FreeSpliceInfoList(&siList);
    fclose(fp);
}