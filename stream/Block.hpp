#ifndef _STREAM_BLOCK_HEADER__
#define _STREAM_BLOCK_HEADER__

#include <string>
#include <string.h>
#include <memory>
#include "OutOfBound.hpp"

namespace stream
{
	//! �ڴ��ṹ
	class Block
	{
	public:
		//! ���캯��
		Block(
			size_t total = 64	//!< �����ݴ�С
			);
		
		//! ��������
		virtual ~Block();

		bool incDataSize(size_t incSize);

		char * buffer;		//!< ������ָ��
		size_t size;		//!< ���ݳ���
		size_t total;		//!< �ܵ����ݴ�С
	};
	
	typedef std::shared_ptr<Block> BlockPtr;

	//! ���캯��
	inline Block::Block( size_t total /*= 64*/)
	{
		this->total = total;
		if (this->total == 0) this->total = 1;
		this->size = 0;
		this->buffer = static_cast<char*>(malloc(total));
	}

	//! ��������
	inline Block::~Block()
	{
		if (this->buffer)
		{
			free(this->buffer);
			this->buffer = NULL;
		}
	}

	inline bool Block::incDataSize(size_t incSize)
	{
		size_t tmpSize = size + incSize;

		if (tmpSize < size)
		{
			throw stream::OutOfBound("wrapped in Block::incDataSize");
		}

		if (tmpSize <= total)
		{
			size = tmpSize;
			return false;
		}

		size_t doubleSize = total;
		while (doubleSize < tmpSize)
		{
			doubleSize <<= 1;
		}
		char* tmpBuffer = static_cast<char*>(malloc(doubleSize));
		memcpy(tmpBuffer, buffer, size);
		free(buffer);
		buffer = tmpBuffer;
		size = tmpSize;
		total = doubleSize;
		return true;
	}
}

#endif
