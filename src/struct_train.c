#include "../include/schedule.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//Ввод поезда

int inputTrain(struct train* new_train, int new_stations_numbers) {
  if (new_stations_numbers < 2) {
    printf("Ошибка ввода количества станций\n");
    return 0;  // Проверяем чтобы количнство остановок было больше 2

  } else {
    new_train->stations_numbers = new_stations_numbers;
    new_train->stations_arr =
        (struct station*)malloc(new_stations_numbers * sizeof(struct station));

    int prev_time = 0;
    for (int j = 0; j < new_stations_numbers; ++j) {
      printf("Введите название станции: ");
      char* name;
      name = (char*)malloc(10);
      scanf("%9s", name);

      printf("Введите время прибытия в формате часы:минуты : ");
      int new_hour = 0;
      int new_min = 0;
      scanf("%d:%d", &new_hour, &new_min);

      printf("Введите время стоянки в минутах: ");
      int new_stay_min = 0;
      scanf("%d", &new_stay_min);

      if (inputStation(&(new_train->stations_arr[j]), name, new_hour, new_min,
                       new_stay_min) == 0) {
        return 0;

      } else if (prev_time >= (new_hour * 60 + new_min)) {
        return 0;

      } else {
        prev_time = new_hour * 60 + new_min + new_stay_min;
      }
    }
  }
  return 1;
}
