#ifndef _PLAYER_HEADER_
#define _PLAYER_HEADER_

#include <iostream>
#include <map>
#include "boardcast/Facade.h"

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
		std::cout << "add hp " << val << std::endl;
		//stream::OStream os;
		//os << std::string("add hp");
		//SEND_NOTIFY(MSG_SEND_MAIL, os.getBlock())	// �����ʼ�
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
		std::function<void(int)> f1 = std::bind(&PlayerListListener::add_hp, this, std::placeholders::_1);
		boardcast::Facade::getRef().regist_notify(MSG_ADD_HP , f1);
	}

	/**
		����ⲿ��Ҫplayerģ������� �� ͨ��listener���ɵĽӿڵ���
	*/
	bool check_have_hp(int val)
	{
		return false;
	}

private:
	void add_hp(int val)
	{
		playerlist_->add_hp(val);
	}

private:
	PlayerList * playerlist_;
};

#endif