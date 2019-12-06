#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  if((addr=growproc(n)) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int
sys_yield(void){
	yield();
	return 0;
}
int
sys_getlev(void){
	return getlev();
}
int sys_setpriority(void){
	int pid, priority;

	if(argint(0,&pid)<0)
		return -1;
	if(argint(1,&priority)<0)
		return -1;
	setpriority(pid, priority);
	return 0;
}
int sys_monopolize(void){
	int password;
	if(argint(0,&password)<0)
		return -1;
	monopolize(password);
	return 0;
}
int sys_thread_create(void){
	int temp;
	thread_t *thread;
	void *(*start_routine)(void *);
	void *arg;
	if(argint(0, &temp)<0)
		return -1;
	thread = (thread_t*)temp;
	if(argint(1, &temp)<0)
		return -1;
	start_routine = (void*)temp;
	if(argint(2, &temp)<0)
		return -1;
	arg = (void*)temp;
	return thread_create(thread, start_routine, arg);
}
int sys_thread_exit(void){
	int temp;
	void *retval;
	if(argint(0, &temp)<0)
		return -1;
	retval = (void*)temp;
	thread_exit(retval);
	return 0;
}
int sys_thread_join(void){
	int temp;
	thread_t thread;
	void **retval;
	if(argint(0, &temp)<0)
		return -1;
	thread = (thread_t)temp;
	if(argint(1, &temp)<0)
		return -1;
	retval = (void**)temp;
	return thread_join(thread, retval);
}
