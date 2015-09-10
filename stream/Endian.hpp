
#ifndef _STREAM_ENDIAN_HEADER__
#define _STREAM_ENDIAN_HEADER__

namespace stream
{
	//! �����ֽڷ�ת
	/*
		@param src	Դ
		@param dst  Ŀ��
	*/
	//@{
	template<typename T>
	inline void reverse(const T & src,T &dst)
	{
		const char * pSrc = reinterpret_cast<const char *>(&src) + sizeof(T) -1;
		char * pDst = reinterpret_cast<char *>(&dst);
		for(int i = 0;i< sizeof(T);++i)
		{
			*pDst++ = *pSrc--;
		}
	}

	inline void reverse(const bool & src,bool &dst)
	{
		dst = src;
	}

	inline void reverse(const char & src,char &dst)
	{
		dst = src;
	}

	inline void reverse(const unsigned char & src,unsigned char & dst)
	{
		dst = src;
	}

	inline void  reverse(const signed char & src,signed char & dst)
	{
		dst = src;
	}
	//@}

	//! ���
	class BigEndian
	{
	public:
		//! ת��
		template <typename T>
		static void convert(
			const T & src,	//!< Դ
			T &dst			//!< Ŀ��
			);
	};

	//! С��
	class LittleEndian
	{
	public:
		template <typename T>
		static void convert(
			const T & src,	//!< Դ
			T &dst			//!< Ŀ��
			);
	};

#if (0x1234&0xFF)==0x12
	typedef BigEndian SystemEndian;
	template <typename T>
	inline void BigEndian::convert(const T & src,T &dst)
	{
		dst = src;
	}
	
	template <typename T>
	inline void LittleEndian::convert(const T & src,T &dst)
	{
		reverse(src,dst);
	}
#else
	typedef LittleEndian SystemEndian;
	template <typename T>
	inline void BigEndian::convert(const T & src,T &dst)
	{
		reverse(src,dst);
	}
	
	template <typename T>
	inline void LittleEndian::convert(const T & src,T &dst)
	{
		dst = src;
	}
#endif	
}

#endif
