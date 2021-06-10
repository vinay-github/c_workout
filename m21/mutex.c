pthread_mutex_t mlock;

int mail=0;
void *func(void *str) {
	char *s = str;

	pthread_mutex_lock(&mlock);
	mail++;
	pthread_mutex_unlock(&mlock);
	printf("%s\n", *str);

	return 0;
}

int main() {
	pthread_t tid;
	pthread_mutex_init(&mlock, NULL);

	pthread_create(&tid, NULL, func, (void *)str);

	ptread_mutex_destory(&mlock);
	return 0;
}



