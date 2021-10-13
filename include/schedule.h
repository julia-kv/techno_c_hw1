#pragma once

struct station {
    int arrival_hour;
    int arrival_min;
    int stay_min;
    char *station_name;
};

struct train {
    int stations_numbers;
    struct station *stations_arr;
};

struct schedule {
    int trains_numbers;
    struct train *trains_arr;
};

int inputStation(struct station* new_station, const char *new_name, int new_hour, int new_min, int new_stay_min);

int inputTrain(struct train* new_train, int new_stations_numbers);

int inputSchedule(struct schedule* new_schedule, int new_trains_number);

int findTime(struct schedule* new_schedule, const char *current_station, const char *goal_station, int current_hour, int current_min);

static int findIndex(struct station* check_station_arr, int n, char *station);
