#pragma warning (disable : 4996);
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

std::vector<bool> button_is_broken(10, 0);
int channel;
int broken_button;
int channel_digit;
std::vector<int> normal_button;

std::string channel_n;

//1107 리모컨 문제
//까다롭지만 어려운 단순히 100000까지의 채널을 돌리는 방식이 최소의 경우의 수를 구하기 위해 탐색하는 과정보다 빠르다
 

int ans;

void calculate(int level) {
	if (level == channel_digit + 2) {
		return;
	}

	if (level != 0) {
		std::string cut = channel_n.substr(0, level);
		int value = std::stoi(cut);
		if (value == 11) {
			printf("");
		}
		if (ans > abs(value - channel) + level) {
			ans = abs(value - channel) + level;
		}
	}

	for (int k = 0; k < normal_button.size(); k++) {
		channel_n[level] = normal_button[k] + '0';
		calculate(level + 1);
	}
	return;
}

int main() {
	scanf("%d", &channel);
	ans = abs(channel-100);
	channel_digit = std::to_string(channel).size();
	scanf("%d", &broken_button);
	for (int k = 0; k < broken_button; k++) {
		int num;
		scanf("%d", &num);
		button_is_broken[num] = true;
	}
	for (int k = 0; k < 10; k++) {
		if (!button_is_broken[k]) normal_button.emplace_back(k);
	}

	while ((int)channel_n.size() != channel_digit + 1) channel_n.push_back('x');
	calculate(0);

	printf("%d", ans);
}
