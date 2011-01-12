#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdbool.h>
#include <stdint.h>
#include <semaphore.h>

struct queueheader {
	uint8_t cur;
	sem_t sem;
};

struct msg {
	uint8_t dir;
	uint8_t data;
};

enum { D_CONV_TO_LOG = 0, D_CONV_TO_STAT, D_STAT_TO_MON, D_INVALID };

void queue_init();
struct msg *queue_write(uint8_t dir, uint8_t data);
uint8_t queue_get_data();
uint8_t queue_get_dir();

#endif
