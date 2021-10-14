#include "schedule.h"
#include "stdio.h"
#include "stdlib.h"

//Ввод расписания

int inputSchedule(struct schedule* new_schedule, int new_trains_number) {
  if (new_trains_number <= 0) {
    return 0;  // Проверяем чтобы количнство поездов было положительно

  } else {
    new_schedule->trains_numbers = new_trains_number;
    new_schedule->trains_arr =
        (struct train*)malloc(new_trains_number * sizeof(struct train));

    for (int i = 0; i < new_trains_number; ++i) {
      printf("Введите количество остановок для поезда: ");
      int stations_numbers = 0;

      if (scanf("%d", &stations_numbers) != 1) {
        return 0;
      }

      printf("\n");

      if (inputTrain(&(new_schedule->trains_arr[i]), stations_numbers) == 0) {
        return 0;
      }
    }
  }

  for (int i = 0; i < new_schedule->trains_numbers; ++i) {
    printf("Train %d: \n", i);
    int n = new_schedule->trains_arr->stations_numbers;
    for (int k = 0; k < n; ++k) {
      printf("Station %s: departure %d:%d\n",
             new_schedule->trains_arr[i].stations_arr[k].station_name,
             new_schedule->trains_arr[i].stations_arr[k].arrival_hour,
             new_schedule->trains_arr[i].stations_arr[k].arrival_min);
    }
  }
  return 1;
}
