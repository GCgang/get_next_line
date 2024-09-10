> # 📁 get_next_line

파일 디스크립터에서 읽은 내용을 한 줄씩 반환하는 `get_next_line()` 구현하기

## ✅ Mandatory part

| **함수 이름**  | `get_next_line`                                                          |
| -------------- | ------------------------------------------------------------------------ |
| **프로토타입** | `char *get_next_line(int fd);`                                           |
| **매개변수**   | 1. fd: 읽을 파일 디스크립터                                              |
| **반환값**     | 읽은 줄: 정상 동작, NULL: 읽을 것이 더 이상 없거나, 오류가 발생했을 경우 |
| **외부 함수**  | `read`, `malloc`, `free`                                                 |
| **설명**       | 파일 디스크립터에서 한 줄을 읽고, 반환하는 함수                          |

<br>

## ✅ Bonus part

- 정적 변수 하나만 사용하여 구현하기
- 여러 파일 디스크립터 관리하기. 예를 들어, fd 3, fd 4, fd 5에서 각각 호출할 때, 각 파일 디스크립터에 대한 읽기 위치를 기억하고 적절한 내용을 반환해야 한다.

<br>

## 🎬 실행 예시

`1.txt`

```
1
1 1
11 11
```

`2.txt`

```
2
2 2
2 2 2
```

`3.txt`

```
3
3 3
3 3 3
33 33
33333
```

`main.c`

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	int fd[3];

	fd[0] = open("1.txt", O_RDONLY);
	fd[1] = open("2.txt", O_RDONLY);
	fd[2] = open("3.txt", O_RDONLY);

	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			char *line = get_next_line(fd[j]);
			if(line != NULL)
				printf("%s", line);
			free(line);
		}
	}

	for(int i = 0; i < 3; i++)
		close(fd[i]);
	return 0;
}
```

`터미널`

```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl

./gnl
1
2
3
1 1
2 2
3 3
11 112 2 23 3 3
33 33
33333%
```

<br>

## ✏️ Review

- 파일 디스크립터에 대해 이해하고, 파일 입출력 처리를 배울 수 있었습니다.
- 정적 변수를 사용하여 함수 호출간 데이터를 유지하는 방법을 배울 수 있었습니다.
- 여러 파일 디스크립터를 처리할 때 각각의 파일에서 데이터를 올바르게 읽고, 메모리를 할당하고 해제하지 않으면 메모리 누수가 발생할 수 있다는 것을 배울 수 있었습니다.
- 파일 디스크립터를 관리할 때 배열과 연결리스트 중 어떤 자료구조를 선택할지 고민하며 차이를 이해하고, 시스템마다 다른 파일디스크립터 제한 개수, 메모리 효율성, 참조/삽입/삭제 등을 고려하며 프로젝트에 적합한 자료구조를 사용하기 위해 노력하였습니다.
