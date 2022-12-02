#include "lock.h"

int Counter=0;

void *
worker(void *arg)
{
  for (uint i = 0; i < NbLoop; i++) {
    pthread_mutex_lock(&Lock);
    Counter++;
    pthread_mutex_unlock(&Lock);
  }

  return NULL;
}

int
main(void)
{
  pthread_t thread[NbThread];

  if ((pthread_mutex_init(&Lock, NULL)) == -1) ERR;

  for (uint i = 0; i < NbThread; i++) {
    pthread_create(&thread[i], NULL, worker, NULL);
  }
  for (uint i = 0; i < NbThread; i++) {
    pthread_join(thread[i], NULL);
  }
  printf("Counter: %u (Ref. %u)\n", Counter, NbThread * NbLoop);

  return 0;
}
