#ifndef _MAIL_HEADER_
#define _MAIL_HEADER_

#include <iostream>

/**!
ģ�� Mail �������ʼ���ص��߼�
MailListener �� Mail ģ��Ψһ�Ķ���ӿ�
*/
class Mail
{
public:
	Mail(){}	// �ⲿ�޷�����

	void send_mail(std::string str)
	{
	}
};

class MailListener : public boardcast::IListener
{
public:
	MailListener()
	{
		mail_ = new Mail();

		init();
	}

	void init()
	{
		boardcast::Facade::getRef().regist_notify(MSG_SEND_MAIL
			, std::bind(&MailListener::send_mail, this, std::placeholders::_1));
	}

private:
	void send_mail(stream::BlockPtr block)
	{
		std::string _str;
		stream::IStream is(block);
		is >> _str;
		mail_->send_mail(_str);
	}

private:

	Mail * mail_;
};

#endif