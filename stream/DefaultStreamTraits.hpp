
#ifndef _STREAM_DEFAULTSTREAMTRAITS_HEADER__
#define _STREAM_DEFAULTSTREAMTRAITS_HEADER__

#include "Endian.hpp"

namespace stream
{
	//! Ĭ����������
	struct DefaultStreamTraits
	{
	public:
		typedef LittleEndian	IntEndian;				//!< ������������
		typedef unsigned short	LengthType;				//!< �ַ�����������
	};
}

#endif
