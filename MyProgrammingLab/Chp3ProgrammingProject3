#include <iostream>
using namespace std;

void breakDown1(int *temp1, int *divBy10_temp1, int *modBy10_temp1,
                int *modBy10_temp1A);
bool tempSelect(int divBy10_temp1, int modBy10_temp1, int modBy10_temp1A);
void breakDown2(int *temp1, int *temp2, int *divBy10_temp1, int *modBy10_temp1A,
                int *modBy10_temp1, int *divBy10_temp2, int *modBy10_temp2,
                int *modBy10_temp2A);
void tempSelect2(int divBy10_temp1, int modBy10_temp1, int modBy10_temp1A,
                 int divBy10_temp2, int modBy10_temp2, int modBy10_temp2A,
                 bool *finished1, bool *finished2);

int main() {
  int temp1, temp2, divBy10_temp1, divBy10_temp2, modBy10_temp1, modBy10_temp2,
      modBy10_temp1A, modBy10_temp2A;
  bool finished1 = false, finished2 = false;
  cin >> temp1;
  while (temp1 < 1 || temp1 > 998) {
    cin >> temp1;
  }
  temp2 = temp1;
  while (finished1 == false && finished2 == false) {
    breakDown1(&temp1, &divBy10_temp1, &modBy10_temp1, &modBy10_temp1A);
    finished1 = tempSelect(divBy10_temp1, modBy10_temp1, modBy10_temp1A);
    finished2 = finished1;
    while (finished1 == false || finished2 == false) {
      if (finished1 == false) {
        temp1--;
      }
      if (finished2 == false) {
        temp2++;
      }
      breakDown2(&temp1, &temp2, &divBy10_temp1, &modBy10_temp1A,
                 &modBy10_temp1, &divBy10_temp2, &modBy10_temp2,
                 &modBy10_temp2A);
      tempSelect2(divBy10_temp1, modBy10_temp1, modBy10_temp1A, divBy10_temp2,
                  modBy10_temp2, modBy10_temp2A, &finished1, &finished2);
    }
  }
  if (temp1 == temp2) {
    cout << temp1 << endl;
  } else {
    cout << temp1 << endl << temp2 << endl;
  }
  return 0;
}

void breakDown1(int *temp1, int *divBy10_temp1, int *modBy10_temp1,
                int *modBy10_temp1A) {
  *divBy10_temp1 = *temp1 / 10;
  *modBy10_temp1 = *temp1 % 10;
  if (*divBy10_temp1 >= 0 && *divBy10_temp1 < 10) {
    return;
  } else {
    *modBy10_temp1A = *divBy10_temp1 % 10;
    *divBy10_temp1 /= 10;
  }
}

bool tempSelect(int divBy10_temp1, int modBy10_temp1, int modBy10_temp1A) {
  if (divBy10_temp1 != 1 && divBy10_temp1 != 4 && divBy10_temp1 != 7 &&
      modBy10_temp1A != 1 && modBy10_temp1A != 4 && modBy10_temp1A != 7 &&
      modBy10_temp1 != 1 && modBy10_temp1 != 4 && modBy10_temp1 != 7) {
    return true;
  } else {
    return false;
  }
}

void breakDown2(int *temp1, int *temp2, int *divBy10_temp1, int *modBy10_temp1A,
                int *modBy10_temp1, int *divBy10_temp2, int *modBy10_temp2,
                int *modBy10_temp2A) {
  *divBy10_temp1 = *temp1 / 10;
  *modBy10_temp1 = *temp1 % 10;
  *divBy10_temp2 = *temp2 / 10;
  *modBy10_temp2 = *temp2 % 10;
  if ((*divBy10_temp1 >= 0 && *divBy10_temp1 < 10) &&
      (*divBy10_temp2 >= 0 && *divBy10_temp2 < 10)) {
    return;
  } else {
    *modBy10_temp1A = *divBy10_temp1 % 10;
    *divBy10_temp1 /= 10;
    *modBy10_temp2A = *divBy10_temp2 % 10;
    *divBy10_temp2 /= 10;
  }
}

void tempSelect2(int divBy10_temp1, int modBy10_temp1, int modBy10_temp1A,
                 int divBy10_temp2, int modBy10_temp2, int modBy10_temp2A,
                 bool *finished1, bool *finished2) {
  if (divBy10_temp1 != 1 && divBy10_temp1 != 4 && divBy10_temp1 != 7 &&
      modBy10_temp1 != 1 && modBy10_temp1 != 4 && modBy10_temp1 != 7 &&
      modBy10_temp1A != 1 && modBy10_temp1A != 4 && modBy10_temp1A != 7) {
    *finished1 = true;
  }
  if (divBy10_temp2 != 1 && divBy10_temp2 != 4 && divBy10_temp2 != 7 &&
      modBy10_temp2 != 1 && modBy10_temp2 != 4 && modBy10_temp2 != 7 &&
      modBy10_temp2A != 1 && modBy10_temp2A != 4 && modBy10_temp2A != 7) {
    *finished2 = true;
  }
}
