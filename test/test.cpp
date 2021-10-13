#include <gtest/gtest.h>

extern "C" {
#include "../include/schedule.h"
}

TEST(INPUT_STATION_TEST, right_input_test) {
    struct station test_station;
    char *station;
    station = "Kurskaya";
    EXPECT_EQ(inputStation(&test_station, station, 5, 5, 5), 1);
}

TEST(INPUT_STATION_TEST, wrong_name_input) {
    struct station test_station;
    char *station;
    station = "\n";
    EXPECT_EQ(inputStation(&test_station, station, 5, 5, 5), 0);
}

TEST(INPUT_STATION_TEST, wrong_hour_input) {
    struct station test_station;
    char *station;
    station = "Kurskaya";
    EXPECT_EQ(inputStation(&test_station, station, -1, 5, 5), 0);
}

TEST(INPUT_STATION_TEST, wrong_hour_input_2) {
    struct station test_station;
    char *station;
    station = "Kurskaya";
    EXPECT_EQ(inputStation(&test_station, station, 100, 5, 5), 0);
}

TEST(INPUT_STATION_TEST, wrong_min_input) {
    struct station test_station;
    char *station;
    station = "Kurskaya";
    EXPECT_EQ(inputStation(&test_station, station, 5, -1, 5), 0);
}

TEST(INPUT_STATION_TEST, right_min_input) {
    struct station test_station;
    char *station;
    station = "Kurskaya";
    EXPECT_EQ(inputStation(&test_station, station, 5, 100, 5), 1);
}

TEST(INPUT_STATION_TEST, wrong_timestay_input) {
    struct station test_station;
    char *station;
    station = "Kurskaya";
    EXPECT_EQ(inputStation(&test_station, station, 5, 5, -1), 0);
}

TEST(INPUT_STATION_TEST, right_timestay_input) {
    struct station test_station;
    char *station;
    station = "Kurskaya";
    EXPECT_EQ(inputStation(&test_station, station, 5, 5, 100), 1);
}

TEST(INPUT_TRAIN_TEST, wrong_input_test) {
    struct train test_train;
    EXPECT_EQ(inputTrain(&test_train, 0), 0);
}

TEST(INPUT_SCHEDULE_TEST, wrong_input_test) {
    struct schedule test_schedule;
    EXPECT_EQ(inputSchedule(&test_schedule, 0), 0);
}

TEST(FIND_TEST, right_input) {
    struct schedule test_schedule;
    test_schedule.trains_numbers = 1;
    test_schedule.trains_arr = (struct train *) malloc(1 * sizeof(struct train));
    test_schedule.trains_arr[0].stations_numbers = 4;
    test_schedule.trains_arr[0].stations_arr = (struct station *) malloc(4 * sizeof(struct station));
    for (int i = 0; i < 4; ++i) {
        char str[10];
        sprintf(str, "%d", i);
        inputStation(&(test_schedule.trains_arr[0].stations_arr[i]), str, i + 6, i * 10 , i * 10 + 10);
    }
    char *station_first;
    station_first = "0";
    char *station_second;
    station_second = "3";
    EXPECT_EQ(findTime(&test_schedule, station_first, station_second, 5, 5), 1);
}

TEST(FIND_TEST, ansver_false) {
    struct schedule test_schedule;
    test_schedule.trains_numbers = 1;
    test_schedule.trains_arr = (struct train *) malloc(1 * sizeof(struct train));
    test_schedule.trains_arr[0].stations_numbers = 4;
    test_schedule.trains_arr[0].stations_arr = (struct station *) malloc(4 * sizeof(struct station));
    for (int i = 0; i < 4; ++i) {
        char str[10];
        sprintf(str, "%d", i);
        inputStation(&(test_schedule.trains_arr[0].stations_arr[i]), str, i + 6, i * 10 , i * 10 + 10);
    }
    char *station_first;
    station_first = "0";
    char *station_second;
    station_second = "3";
    EXPECT_EQ(findTime(&test_schedule, station_first, station_second, 23, 23), 0);
}

TEST(FIND_TEST, wrong_inputhour_test) {
    struct schedule test_schedule;
    test_schedule.trains_numbers = 1;
    test_schedule.trains_arr = (struct train *) malloc(1 * sizeof(struct train));
    test_schedule.trains_arr[0].stations_numbers = 4;
    test_schedule.trains_arr[0].stations_arr = (struct station *) malloc(4 * sizeof(struct station));
    for (int i = 0; i < 4; ++i) {
        char str[10];
        sprintf(str, "%d", i);
        inputStation(&(test_schedule.trains_arr[0].stations_arr[i]), str, i + 6, i * 10 , i * 10 + 10);
    }
    char *station_first;
    station_first = "0";
    char *station_second;
    station_second = "3";
    EXPECT_EQ(findTime(&test_schedule, station_first, station_second, -10, 0), 0);
}

TEST(FIND_TEST, wrong_inputmin_test) {
    struct schedule test_schedule;
    test_schedule.trains_numbers = 1;
    test_schedule.trains_arr = (struct train *) malloc(1 * sizeof(struct train));
    test_schedule.trains_arr[0].stations_numbers = 4;
    test_schedule.trains_arr[0].stations_arr = (struct station *) malloc(4 * sizeof(struct station));
    for (int i = 0; i < 4; ++i) {
        char str[10];
        sprintf(str, "%d", i);
        inputStation(&(test_schedule.trains_arr[0].stations_arr[i]), str, i + 6, i * 10 , i * 10 + 10);
    }
    char *station_first;
    station_first = "0";
    char *station_second;
    station_second = "3";
    EXPECT_EQ(findTime(&test_schedule, station_first, station_second, 5, -10), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
