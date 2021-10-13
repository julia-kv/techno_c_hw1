#include "../include/schedule.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/schedule.h"
 
//Создание станции с проверкой введения времени прибытия/отправления на станцию
 
int inputStation(struct station* new_station, char *new_name, int new_hour, int new_min, int new_stay_min) {
int inputStation(struct station* new_station,
                 char* new_name,
                 int new_hour,
                 int new_min,
                 int new_stay_min) {
  if ((new_hour <= -1) || (new_hour >= 24) || (new_min <= -1) ||
      (new_stay_min < 1)) {
    printf("Ошибка ввода времени\n");
    return 0;

    if ((new_hour <= -1) || (new_hour >= 24) || (new_min <= -1) || (new_stay_min < 1)) {
        printf("Ошибка ввода времени\n");
        return 0;
  } else {
    new_station->arrival_min = new_min % 60;
    new_station->arrival_hour = (new_hour + new_min / 60) % 24;
    new_station->stay_min = new_stay_min;

    if (strcmp(new_name, "\n") == 0) {
      printf("Ошибка ввода названия станции\n");
      return 0;

    } else {
        new_station->arrival_min = new_min % 60;
        new_station->arrival_hour = (new_hour + new_min / 60) % 24;
        new_station->stay_min = new_stay_min;

        if (strcmp(new_name, "\n") == 0) {
            printf("Ошибка ввода названия станции\n");
            return 0;

        } else {
            new_station->station_name = (char *) malloc(10);
            strcpy(new_station->station_name, new_name);
        }
      new_station->station_name = (char*)malloc(10);
      strcpy(new_station->station_name, new_name);
    }
    return 1;
  }
  return 1;
}
