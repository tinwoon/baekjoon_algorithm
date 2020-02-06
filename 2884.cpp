#include <iostream>

int main() {
	int hour, minute;
	bool over_45 = false;
	scanf("%d %d", &H, &M);

	if (minute < 45) {
		minute += 15;
		over_45 = true;
	}
	else minute -= 45;

	if (over_45) {
		if (hour) hour -= 1;
		else hour = 23;
	}
	printf("%d %d\n", hour, minute);
	return 0;
}
