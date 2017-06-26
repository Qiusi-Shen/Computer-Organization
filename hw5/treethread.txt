#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>

int numLevel = 0;

struct args
{
	int thread;
	int level;
};

void * thread(void *vargp);

int main(int argv, char ** argc) {
	numLevel = atoi(argc[1]);
    int numthreads = 2<<numLevel - 2;
    int threadNum = 0;
    if (numthreads == 0)
      printf("Thread %i done\n", threadNum); 
    else {
		int ch1 = (2 * threadNum) +1;
		int ch2 = (2 * threadNum) +2;

		struct args Left_Child;
		struct args Right_Child;
		pthread_t tid1;
                pthread_t tid2;
		Left_Child.thread = ch1;
		Left_Child.level = 2;

		Right_Child.thread = ch2;
		Right_Child.level = 2;

		if (pthread_create(&tid1, 0, thread, &Left_Child)||
                    pthread_create(&tid2, 0, thread, &Right_Child)||
                    pthread_join(tid1, NULL) ||
                    pthread_join(tid2, NULL))
                  printf("Cannot crreat thread!");

		printf("Thread %i done\n", threadNum);
    }

    return(0);
}

void * thread(void *vargp) {
        struct args arg = * (struct args *) vargp;
        int threadLevel = arg.level;
        if (threadLevel == numLevel) {
          printf("Thread %i done\n", arg.thread);
                return NULL;
        }
        else
        {
                struct args Left_Child;
                struct args Right_Child;
                pthread_t tid1;
                pthread_t tid2;

                Left_Child.thread = (2 * arg.thread) + 1;
                Left_Child.level = threadLevel + 1;

                Right_Child.thread = (2 * arg.thread) + 2;
                Right_Child.level = threadLevel + 1;

                if (pthread_create(&tid1, 0, thread, &Left_Child)||
                    pthread_create(&tid2, 0, thread, &Right_Child)||
                    pthread_join(tid1, NULL) ||
                    pthread_join(tid2, NULL))
                  printf("Cannot crreat thread!");

                printf("Thread %i done\n", arg.thread);
                return NULL;
        }
}
