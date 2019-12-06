#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_NUM 40

int arr[MAX_NUM];
int sorted[MAX_NUM];
int check_sorted(int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] != i)
            return 0;
    return 1;
}

// Implement your solution here
void merge(int list[], int left, int mid, int right){
	int i, j, k , l;
	i = left;
	j = mid+1;
	k = left;
	while(i<=mid && j <= right){
		if(list[i]<=list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if(i>mid){
		for(l = j ; l<=right;l++)
			sorted[k++]=list[l];
	}
	else{
		for(l=i; l<=mid;l++)
			sorted[k++] = list[l];
	}
	for(l=left;l<=right;l++){
		list[l]=sorted[l];
	}
}
void Merge_sort(int left, int right){
	int mid;
	if(left<right){
		mid = (left+right)/2;
		Merge_sort(left,mid);
		Merge_sort(mid+1,right);
		merge(arr,left,mid,right);
	}
}
void *mergeThread(void *arg){
	int tid;
	tid = (int)arg;
	Merge_sort(tid,tid+(MAX_NUM/4)-1);
	pthread_exit(NULL);
}

///////////////////////////////

int main(void)
{
    srand((unsigned int)time(NULL));
    const int n = MAX_NUM;
    int i;
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	void *status;
    for (i = 0; i < n; i++){
        arr[i] = i;
	}
    for (i = n - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    printf("Sorting %d elements...\n", n);

    // Create threads and execute.
	for(t=0;t<NUM_THREADS;t++){
	long targ=t*(MAX_NUM/4);
	printf("Creating thread %d\n",t);
	rc = pthread_create(&threads[t],NULL,mergeThread,(void *)targ);
	if(rc){
		printf("ERROR; return code from pthread_create() is %d\n",rc);
		exit(-1);
	}
	}
	for(t=0;t<NUM_THREADS;t++){
		rc=pthread_join(threads[t],&status);
		if(rc){
			printf("ERROR; return code from pthread_join() is %d\n",rc);
			exit(-1);
		}
		printf("Main : completed join with thread %ld having a status of %ld\n", t, (long)status);
	}
	Merge_sort(0,MAX_NUM/2-1);
	Merge_sort(MAX_NUM/2,MAX_NUM-1);
	Merge_sort(0,MAX_NUM-1);


    //////////////////////////////
	for(int check = 0; check<40;check++)
		printf("%d\n",arr[check]);

    if (!check_sorted(n))
    {
        printf("Sort failed!\n");
        return 0;
    }

    printf("Ok %d elements sorted\n", n);
    return 0;
}
