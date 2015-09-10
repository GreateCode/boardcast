#ifndef _PLAYER_HEADER_
#define _PLAYER_HEADER_

#include <iostream>
#include <Facade.h>

/**!
	ģ�� Player ���������ҵ����� �� ��Ϊ
	ģ�� PlayerList �����������б�

	PlayerListListener �����ģ��Ψһ�Ķ���ӿ�
*/

class Player
{
public:
	void add_hp(int val)
	{
		std::cout << "player : add hp " << val << std::endl;

		stream::OStream os;
		os << std::string("add hp");
		SEND_NOTIFY(MSG_SEND_MAIL, os.getBlock())	// �����ʼ�
	}
};

class PlayerList
{
	typedef std::map<int, Player*> PlayerMap;
public:

	PlayerList()
	{
		playermap_.insert(PlayerMap::value_type(1, new Player()));
	}

	void add_hp(int val)
	{
		auto itr = playermap_.find(1);
		itr->second->add_hp(val);
	}

private:
	PlayerMap playermap_;
};

class PlayerListListener : public boardcast::IListener
{
public:

	PlayerListListener()
	{
		playerlist_ = new PlayerList();

		init();
	}

	void init()
	{
		boardcast::Facade::getRef().regist_notify(MSG_ADD_HP
			, std::bind(&PlayerListListener::add_hp, this, std::placeholders::_1));
	}

	/**
		����ⲿ��Ҫplayerģ������� �� ͨ��listener���ɵĽӿڵ���
	*/
	bool check_have_hp(int val)
	{
		return false;
	}

private:
	void add_hp(stream::BlockPtr block)
	{
		int _val;
		stream::IStream is(block);
		is >> _val;

		playerlist_->add_hp(_val);
	}

private:
	PlayerList * playerlist_;
};

#endif