#pragma once
#include <list>
#include <any>
#include <Windows.h>
#include <iostream>
#include <map>
#include <string_view>
#include <thread>

#include "get_type.h"

bool ThreadInnit();

enum thread_error
{
	FUNCTION_STILL_ACTIVE
};

class thread
{
private:
	friend class ThreadPool;

	class thread_data_storage_container
	{
	public:

		class type_embedder_t
		{
		public:
			template<typename type_t>
			type_embedder_t(type_t data_t)
			{
				data = data_t;
				type = get_type(data_t);
			}

			~type_embedder_t()
			{

			}

			std::any data = NULL;
			std::string_view type = NULL;

		};

		std::any function_final = NULL;
		std::any arguments_final = NULL;
		unsigned int priority_final = 0;

		template<typename FunctionType>
		thread_data_storage_container(const FunctionType* function, unsigned int priority)
		{

		}

		template<typename FunctionType, typename ArgType>
		thread_data_storage_container(const FunctionType* function, ArgType argument, unsigned int priority)
		{

		}

		template<typename FunctionType, typename ... ArgTypes>
		thread_data_storage_container(const FunctionType* function, std::tuple<ArgTypes...> arguments, unsigned int priority)
		{

		}

		~thread_data_storage_container()
		{

		}
	};

	template<typename FunctionType>
	class thread_data_storage1
	{
	public:
		thread_data_storage1() {}
		~thread_data_storage1() {}

		unsigned int PRIORITY = 0;
		const FunctionType* FUNCTION;
	};

	template<typename FunctionType, typename ArgType>
	class thread_data_storage2
	{
	public:
		thread_data_storage2() {}
		~thread_data_storage2() {}

		const FunctionType* FUNCTION;
		ArgType ARGUMENT;
		unsigned int PRIORITY = 0;
	};

	template<typename FunctionType, typename ... ArgsType>
	class thread_data_storage3
	{
	public:
		thread_data_storage3() {}
		~thread_data_storage3() {}

		const FunctionType* FUNCTION;
		std::tuple<ArgsType...> ARGUMENTS;
		unsigned int PRIORITY = 0;
	};

public:
	template<typename FunctionType>
	thread(const FunctionType* function)
	{
		thread_data_storage1<FunctionType> DATA_STORAGE;
		DATA_STORAGE.FUNCTION = function;

	}

	template<typename FunctionType, typename ArgType>
	thread(const FunctionType* function, ArgType argument1)
	{
		thread_data_storage2<FunctionType, ArgType> DATA_STORAGE;
		DATA_STORAGE.FUNCTION = function;
		DATA_STORAGE.ARGUMENT = argument1;

	}

	template<typename FunctionType, typename ... ArgTypes>
	thread(const FunctionType* function, ArgTypes ... arguments)
	{
		thread_data_storage3<FunctionType, ArgTypes...> DATA_STORAGE;
		DATA_STORAGE.FUNCTION = function;
		std::tuple<ArgTypes...> local_ARGUMENTS{ arguments... };
		DATA_STORAGE.ARGUMENTS = local_ARGUMENTS;
	}

	// Constructors with priorities:

	template<typename FunctionType>
	thread(const FunctionType* function, unsigned long long int priority)
	{
		thread_data_storage1<FunctionType> DATA_STORAGE;
		DATA_STORAGE.FUNCTION = function;
		DATA_STORAGE.PRIORITY = priority;

	}

	template<typename FunctionType, typename ArgType>
	thread(const FunctionType* function, ArgType argument1, unsigned long long int priority)
	{
		thread_data_storage2<FunctionType, ArgType> DATA_STORAGE;
		DATA_STORAGE.FUNCTION = function;
		DATA_STORAGE.PRIORITY = priority;
		DATA_STORAGE.ARGUMENT = argument1;
	}

	template<typename FunctionType, typename ... ArgTypes>
	thread(const FunctionType* function, ArgTypes ... arguments, unsigned long long int priority)
	{
		thread_data_storage3<FunctionType, ArgTypes...> DATA_STORAGE;
		DATA_STORAGE.FUNCTION = function;
		DATA_STORAGE.PRIORITY = priority;
		std::tuple<ArgTypes...> local_ARGUMENTS{ arguments... };
		DATA_STORAGE.ARGUMENTS = local_ARGUMENTS;
	}

	auto GetReturnValue();

	~thread();
};

