#include <catch2/catch.hpp>
#include "../lib/scte35_types.h"

#include <cstdio>

#include <iostream>

TEST_CASE("ParseSCTE35FromByteArray.scte35_1") {
    FILE *fp = fopen("../../test/cases/scte35_1.bin", "rb");

    splice_info_section_struct_list_t *siList = nullptr;
    ParseSCTE35FromByteArray(fp, &siList);

//    FILE *fp2 = fopen("/tmp/x.scte35", "w");
//    PrintParsedSCTE35ToFile(fp2, siList);
//    fclose(fp2);
//    PrintParsedSCTE35ToFile(NULL, siList);

    splice_insert_t *si = (splice_insert_t *) siList->splice_info_section->splice_command_ptr;
    CHECK(si->splice_immediate_flag == false);

    CHECK(si->splice_time.pts_time - siList->next->splice_info_section->pts_adjustment - 1 == 4599504262);

    CHECK(si->unique_program_id == 7030);
    CHECK(si->out_of_network_indicator == true);
    CHECK(si->break_duration.duration / 90 == 15000); // 15s
    CHECK(si->splice_event_id == 821094442);
    CHECK(si->splice_event_cancel_indicator == false);

    FreeSpliceInfoList(&siList);
    fclose(fp);
}

TEST_CASE("ParseSCTE35FromByteArray - splice schedule") {
    FILE *fp = fopen("../../test/cases/scte35_2.bin", "rb");

    splice_info_section_struct_list_t *siList = nullptr;
    ParseSCTE35FromByteArray(fp, &siList);

    const auto ss = (splice_schedule_t *) siList->splice_info_section->splice_command_ptr;
    CHECK(ss->splice_count == 1);
    const auto sse = ss->splice_schedule_event_t[0];
//  si->splice_immediate_flag ??
//    CHECK(sse.utc_splice_time.pts_time - siList->next->splice_info_section->pts_adjustment - 1 == -627096585282);
    CHECK(sse.unique_program_id == 4343);
    CHECK(sse.out_of_network_indicator == true);
    CHECK(sse.break_duration.duration / 90 == 120000); // 120s
    CHECK(sse.splice_event_id == 821102409);
    CHECK(sse.splice_event_cancel_indicator == false);

    FreeSpliceInfoList(&siList);
    fclose(fp);
}