#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <Facade.h>

/////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	new boardcast::Facade();

	int _hp = 10;

	// ����������tuple ����û�취�����ͱ� ��������������ʵ��
	stream::OStream os;
	os << _hp;
	SEND_NOTIFY(MSG_ADD_HP, os.getBlock())		// �ӵ�Ѫ

	system("pause");
	return 0;
}