#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/schedule.h"

// Поиск времени отправления со станции
 
int findTime(struct schedule* new_schedule, char *current_station, char *goal_station, int current_hour, int current_min) {
int findTime(struct schedule* new_schedule,
             char* current_station,
             char* goal_station,
             int current_hour,
             int current_min) {
  if ((current_hour <= -1) || (current_hour >= 24) || (current_min <= -1)) {
    printf("Ошибка ввода времени\n");
    return 0;

    if ((current_hour <= -1) || (current_hour >= 24) || (current_min <= -1)) {
        printf("Ошибка ввода времени\n");
        return 0;
  } else {
    current_hour = (current_hour + current_min / 60) % 24;
    current_min = current_min % 60;
  }

    } else {
        current_hour = (current_hour + current_min / 60) % 24;
        current_min = current_min % 60;
  if (!strcmp(current_station, goal_station)) {
    printf("Вы уже на этой станции\n");
    return 1;
  }

  int min_time_gap =
      2000;  // максимально возможное время ожидания поезда минутах 24 * 60
  int train_index = -1;
  int station_index = -1;

  for (int i = 0; i < new_schedule->trains_numbers; ++i) {
    struct station* new_station_arr = new_schedule->trains_arr[i].stations_arr;
    int goal_index =
        findIndex(new_station_arr, new_schedule->trains_arr[i].stations_numbers,
                  goal_station);
    int current_index =
        findIndex(new_station_arr, new_schedule->trains_arr[i].stations_numbers,
                  current_station);
    //            printf("HERE %d  %d\n", current_station_index,
    //            goal_station_index);

    if ((current_index != -1) && (goal_index != -1) &&
        (current_index < goal_index)) {
      int departure_time =
          new_schedule->trains_arr[i].stations_arr[goal_index].arrival_hour *
              60 +
          new_schedule->trains_arr[i].stations_arr[goal_index].arrival_min +
          new_schedule->trains_arr[i].stations_arr[goal_index].stay_min;

      if (current_hour * 60 + current_min < departure_time) {
        int time_gap = departure_time - current_hour * 60 + current_min;

        if (time_gap <= min_time_gap) {
          min_time_gap = time_gap;
          train_index = i;
          station_index = current_index;
        }
      }
    }
  }

    if (!strcmp(current_station,goal_station)) {
        printf("Вы уже на этой станции\n");
        return 1;
    }
  if (train_index == -1) {
    printf("Нет подходящих поездов\n");
    return 0;

    int min_time_gap = 2000; // максимально возможное время ожидания поезда минутах 24 * 60
    int train_index = -1;
    int station_index = -1;

    for (int i = 0; i < new_schedule->trains_numbers; ++i) {
        struct station *new_station_arr = new_schedule->trains_arr[i].stations_arr;
        int goal_index = findIndex(new_station_arr, new_schedule->trains_arr[i].stations_numbers,
                                   goal_station);
        int current_index = findIndex(new_station_arr, new_schedule->trains_arr[i].stations_numbers,
                                      current_station);

        if ((current_index != -1) && (goal_index != -1) && (current_index < goal_index)) {
            int departure_time = new_schedule->trains_arr[i].stations_arr[goal_index].arrival_hour * 60 +
                                 new_schedule->trains_arr[i].stations_arr[goal_index].arrival_min +
                                 new_schedule->trains_arr[i].stations_arr[goal_index].stay_min;

            if (current_hour * 60 + current_min < departure_time) {
                int time_gap = departure_time - current_hour * 60 + current_min;

                if (time_gap <= min_time_gap) {
                    min_time_gap = time_gap;
                    train_index = i;
                    station_index = current_index;
                }
            }
        }
    }

    if (train_index == -1) {
        printf("Нет подходящих поездов\n");
        return 0;

    } else {
        int min = (new_schedule->trains_arr[train_index].stations_arr[station_index].arrival_min + new_schedule->trains_arr[train_index].stations_arr[station_index].stay_min) % 60;
        int hour = new_schedule->trains_arr[train_index].stations_arr[station_index].arrival_hour + (new_schedule->trains_arr[train_index].stations_arr[station_index].arrival_min + new_schedule->trains_arr[train_index].stations_arr[station_index].stay_min) / 60;
        printf("Время отправления ближайшего поезда со странции %s - %d:%d\n", goal_station, hour, min);
    }
    return 1;
  } else {
    int min = (new_schedule->trains_arr[train_index]
                   .stations_arr[station_index]
                   .arrival_min +
               new_schedule->trains_arr[train_index]
                   .stations_arr[station_index]
                   .stay_min) %
              60;
    int hour = new_schedule->trains_arr[train_index]
                   .stations_arr[station_index]
                   .arrival_hour +
               (new_schedule->trains_arr[train_index]
                    .stations_arr[station_index]
                    .arrival_min +
                new_schedule->trains_arr[train_index]
                    .stations_arr[station_index]
                    .stay_min) /
                   60;
    printf("Время отправления ближайшего поезда со странции %s - %d:%d\n",
           goal_station, hour, min);
  }
  return 1;
}
