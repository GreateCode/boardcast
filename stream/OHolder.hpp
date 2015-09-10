#ifndef _STREAM_OHOLDER_HEADER__
#define _STREAM_OHOLDER_HEADER__

#include <string>
#include "Block.hpp"

namespace stream
{
	//! ���ռλ���ṹ
	/*!
		����T����ΪPOD����
	*/
	template <class T>
	class OHolder
	{
		template <typename Traints>
		friend class OutputStream;
	public:
		//! ���캯��
		OHolder();

		OHolder & operator=(const T & v);

		operator T & ();
	private:
		BlockPtr	m_block;
		size_t		m_position;	
	};

	template <class T>
	inline OHolder<T>::OHolder()
	{
	}

	template <class T>
	inline OHolder<T> & OHolder<T>::operator=(const T & v)
	{
		* reinterpret_cast<T*>(m_block->buffer + m_position) = v;
		return *this;
	}

	template <class T>
	inline OHolder<T>::operator T & ()
	{
		return *reinterpret_cast<T*>(m_block->buffer + m_position);
	}
}

#endif
