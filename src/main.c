#include "../include/schedule.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
  printf("Создайте расписание поездов\n");
  printf("\n");

  struct schedule new_schedule;

  printf("Введите количество поездов в расписании: ");
  int new_trains_number = 0;
  scanf("%d", &new_trains_number);
  printf("\n");

  if (inputSchedule(&new_schedule, new_trains_number) == 0) {
    printf("Расписание не создалось\n");
    return 0;

  } else {
    printf("Поиск времения отправления ближайшего поезда\n");
    printf("Введите название ближайшей станции: ");
    char* current_station;
    current_station = (char*)malloc(10);

    if (scanf("%9s", current_station) != 1) {
      return 0;
    }

    printf("Введите название станции, до которой нужно добраться: ");
    char* goal_station;
    goal_station = (char*)malloc(10);
    scanf("%9s", goal_station);

    printf("Введите время формате часы:минуты : ");
    int new_hour = 0;
    int new_min = 0;

    if (scanf("%d%d", &new_hour, &new_min) != 2) {
      retern 0;
    }

    if (findTime(&new_schedule, current_station, goal_station, new_hour,
                 new_min) == 0) {
      return 0;
    }
  }

  return 1;
}
