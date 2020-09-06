#define ENUM_MAX 10000
int deadendsCmp(char* posCur, char** deadends, int deadendsSize)
{
	int i;
	for (i = 0; i < deadendsSize; i++) {
		if (!strcmp(posCur, deadends[i])) {
			return 0;
		}
	}
	return 1;
}

int isVisted(char* posNew, int* visit, int lockSize)
{
	int i, id = 0;
	for (i = 0; i < lockSize; i++) {
		id = id * 10 + posNew[i] - '0';
	}
	if (visit[id] == 1) {
		return 1;
	}
	else {
		visit[id] = 1;
		return 0;
	}
}
int openLock(char** deadends, int deadendsSize, char* target) {
	if (deadends == NULL || deadendsSize <= 0 || target == NULL)
		return -1;
	int lockSize = 4;
	int i, j, k, d, head = 0, tail = 0, num = 0;
	int visit[ENUM_MAX] = { 0 };
	char* posCur = (char*)malloc(sizeof(char) * (lockSize + 1));
	char* posNew = (char*)malloc(sizeof(char) * (lockSize + 1));
	char** queue = (char**)malloc(sizeof(char*) * ENUM_MAX);
	int direction[][4] = {
		{ -1,0,0,0 },{ 1,0,0,0 },
		{ 0,-1,0,0 },{ 0,1,0,0 },
		{ 0,0,-1.0 },{ 0,0,1,0 },
		{ 0,0,0,-1 },{ 0,0,0,1 }
	};
	for (i = 0; i < ENUM_MAX; i++) {
		queue[i] = (char*)malloc(sizeof(char) * (lockSize + 1));
	}
	//初始化
	for (i = 0; i < lockSize; i++)
		posCur[i] = '0';
	posCur[i] = '\0';
	if (!strcmp(posCur, target))
		return num;
	else if (!deadendsCmp(posCur, deadends, deadendsSize))
		return -1;
	for (i = 0; i < lockSize; i++) {
		queue[tail][i] = posCur[i];
	}
	queue[tail][i] = '\0';
	tail++;
	visit[0] = 1;
	while (head < tail) {
		int start = head, end = tail;
		num++;
		for (i = start; i < end; i++) {
			for (j = 0; j < lockSize; j++)
				posCur[j] = queue[i][j];
			head++;
			for (d = 0; d < sizeof(direction) / sizeof(direction[0]); d++) {
				//基于当前锁位置移动任一步有8种可能
				for (k = 0; k < lockSize; k++) {
					if (posCur[k] == '0' && direction[d][k] == -1)
						posNew[k] = '9';
					else if (posCur[k] == '9' && direction[d][k] == 1)
						posNew[k] = '0';
					else
						posNew[k] = posCur[k] + direction[d][k];
				}
				posNew[k] = '\0';
				if (!strcmp(posNew, target))
					return num;
				else if (isVisted(posNew, visit, lockSize) || !deadendsCmp(posNew, deadends, deadendsSize))
					continue;
				for (k = 0; k < lockSize; k++)
					queue[tail][k] = posNew[k];
				tail++;
			}
		}
	}
	return -1;
}
