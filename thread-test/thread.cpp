#include "thread.h"

class ThreadPool
{
private:
	friend class thread;
	//std::list<std::tuple<thread::thread_data_storage1, thread::thread_data_storage2, thread::thread_data_storage3>>
public:
	ThreadPool();
	~ThreadPool();
};

static bool IfInnit = false;
static ThreadPool* thread_pool = nullptr;

bool ThreadInnit()
{
	if (!IfInnit) { thread_pool = new ThreadPool(); IfInnit = true; return true; }
	else if (IfInnit) { std::cout << "ThreadPool already Innitualised" << std::endl; return false; }
}

ThreadPool::ThreadPool()
{

}

ThreadPool::~ThreadPool()
{

}

auto thread::GetReturnValue()
{
	// If function has not returned yet:
	return FUNCTION_STILL_ACTIVE;
}

thread::~thread()
{

}