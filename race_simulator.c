#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};
// Print functions section
void printIntro() {
  printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown() {
  printf("Racers Ready! In...\n");
  for (int i = 0; i < 5; i++) {
    printf("%d\n", i+1);
  }
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %d\n", race.currentLap);
  printf("First Place is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
// Logic functions section
int calculateTimeToCompleteLap() {
  int speed = rand() % 3 + 1;
  int acceleration = rand() % 3 +1;
  int nerves = rand() % 3 + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  } else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}


void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for (int i = 0; i < race.numberOfLaps; i++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  }
  printCongratulation(race);
}

int main() {
  struct RaceCar raceCar1 = {"Tolga Porsuk", "green", 0};
  struct RaceCar raceCar2 = {"Fatma Düpon", "beige", 0};
  
	srand(time(0));
  printIntro();
  printCountDown();
  startRace(&raceCar1, &raceCar2);
};
