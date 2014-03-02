//
//  BlockingQueue.h
//
//  Created by zhouyan on 2013-01-07.
//

#ifndef __BLOCKING_QUEUE_H__
#define __BLOCKING_QUEUE_H__

#include <list>
#include <pthread.h>

using namespace std;

template <typename T>
class BlockingQueue {
public:
	BlockingQueue();
	~BlockingQueue();

	void add(T item);
	T remove();
	int size();

private:
	list<T> queue;
	pthread_mutex_t mutex;
	pthread_cond_t cond;

};

template <typename T>
BlockingQueue<T>::BlockingQueue() : queue() {
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);
};

template <typename T>
BlockingQueue<T>::~BlockingQueue() {
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}

template <typename T>
void BlockingQueue<T>::add(T item) {
	pthread_mutex_lock(&mutex);
	queue.push_back(item);
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);
}

template <typename T>
T BlockingQueue<T>::remove() {
	pthread_mutex_lock(&mutex);
	while (queue.size() == 0) {
		pthread_cond_wait(&cond, &mutex);
	}
	T item = queue.front();
	queue.pop_front();
	pthread_mutex_unlock(&mutex);
	return item;
}

template <typename T>
int BlockingQueue<T>::size() {
	pthread_mutex_lock(&mutex);
	int size = queue.size();
	pthread_mutex_unlock(&mutex);
	return size;
}

#endif  // __BLOCKING_QUEUE_H__
