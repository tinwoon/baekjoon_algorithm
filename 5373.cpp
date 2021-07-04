#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

//5373 백준 루빅스 큐브 문제
// 노가다 뿐이니 그냥 외우는 게 나을 듯하다. 

char cube[6][3][3] = { { {'w','w','w'},
						{'w','w','w'}, 
						{'w','w','w'} },

					  { {'y','y','y'},
						{'y','y','y'},
						{'y','y','y'} },

					  { {'r','r','r'},
						{'r','r','r'},
						{'r','r','r'} },

					  { {'o','o','o'},
						{'o','o','o'},
						{'o','o','o'} },

					  { {'g','g','g'},
						{'g','g','g'},
						{'g','g','g'} },

					  { {'b','b','b'},
						{'b','b','b'},
						{'b','b','b'} },
};

//위가 ~일때 바퀴는 4개의 사이드
//예를들어 U이면 위(B) 오른쪽(R) 아래(F) 왼쪽(L) 순으로 해당 면을 알려준다
//   0   1     2    3    4    5
//{ 'U', 'D', 'F', 'B', 'L', 'R' };
//0번에는 B,R,F,L의 인덱스를 확인할 수 있다.
int index_change[6][4] = { {3, 5, 2, 4}, {2, 5, 3, 4}, {0, 5, 1, 4}, {0, 4, 1, 5}, {0, 2, 1, 3}, {0, 3, 1, 2} };

//바꿔야하는 인덱스의 번호가 적혀있다.
//예를 들면 0번 인덱스의 경우 위부터 시작하면 B의 2,1,0번, R의 2,1,0번 F의 2,1,0번, L의 2,1,0번이므로 210, 210, 210, 210이 순서대로 들어간다
int change_size[6][4][3] = {
					  { {2,1,0}, {2,1,0}, {2,1,0}, {2,1,0} },
					  { {6,7,8}, {6,7,8}, {6,7,8}, {6,7,8} },
					  { {6,7,8}, {0,3,6}, {2,1,0}, {8,5,2} },
					  { {2,1,0}, {0,3,6}, {6,7,8}, {8,5,2} },
					  { {0,3,6}, {0,3,6}, {0,3,6}, {8,5,2} },
					  { {8,5,2}, {0,3,6}, {8,5,2}, {8,5,2} },
};

int N;
char cube_map[6][3][3];
char side[6] = { 'U', 'D', 'F', 'B', 'L', 'R' };
std::vector< std::string > cmd_d;


void rotate(int side_val, int dir) {
	char cube_tmp[6][3][3];
	memcpy(cube_tmp, cube_map, sizeof(cube_map));
	for (int k = 0; k < (dir == 1 ? 1 : 3); k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cube_tmp[side_val][i][j] = cube_map[side_val][2 - j][i];
			}
		}
		memcpy(cube_map, cube_tmp, sizeof(cube_map));
	}
	
	for (int k = 0; k < (dir == 1 ? 3 : 1); k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				cube_tmp[index_change[side_val][i]][change_size[side_val][i][j] / 3][change_size[side_val][i][j] % 3] = cube_map[index_change[side_val][(i + 1) % 4]][change_size[side_val][(i + 1) % 4][j] / 3][change_size[side_val][(i + 1) % 4][j] % 3];
			}
		}
		memcpy(cube_map, cube_tmp, sizeof(cube_map));
	}
	
	return;
}


void calculate(int count) {
	for (int k = 0; k < count; k++) {
		for (int side_t = 0; side_t < 6; side_t++) {
			//명령어의 UDFBLR을 확인하는 내용
			if (cmd_d[k][0] == side[side_t]) {
				rotate(side_t, cmd_d[k][1] == '+' ? 1 : 0);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%1c", cube_map[0][i][j]);
		}
		printf("\n");
	}
}

int main() {
	std::cin >> N;
	while (N--) {
		cmd_d.clear();
		memcpy(cube_map, cube, sizeof(cube_map));
		int count;
		scanf("%d", &count);
		for (int k = 0; k < count; k++) {
			std::string cmd;
			std::cin >> cmd;
			cmd_d.emplace_back(cmd);
		}
		calculate(count);
	}
}
