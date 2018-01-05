#include "GroupObject.h"
#include "GameObject.h"
#include "QNode.h"
#include "World.h"

GroupObject::GroupObject()
{
}

GroupObject::GroupObject(World * manager)
{
	this->manager = manager;
}


GroupObject::~GroupObject()
{
}

std::vector<GameObject*> GroupObject::GetListGO()
{
	return objects;
}

int GroupObject::GetSize()
{
	return size;
}

void GroupObject::AddGameObject(GameObject * target)
{
	// trước khi thêm kiểm tra trùng lặp
	for (int i = 0; i < size; i++)
	{
		// Nếu trùng thì dừng
		if (objects[i] == target)
			return;
	}

	objects.push_back(target);
	size++;
}

void GroupObject::Update(float t)
{
	for (int i = 0; i < size; i++)
	{
		objects[i]->Update(t);
	}
}

void GroupObject::UpdateActive(float t)
{
	for (int i = 0; i < size; i++)
	{
		if (objects[i]->IsActive())
		{
			objects[i]->Update(t);
		}
	}
}

void GroupObject::Render()
{
	// Do trong mỗi GameObject đã có kiểm tra isActive trước khi render 
	// nên không cần kiểm tra nữa
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Render();
	}
}

void GroupObject::GetGroupObjectFrom(GroupObject * group)
{
	int group_size = group->size;
	for (int i = 0; i < group_size; i++)
	{
		// Chỉ lấy những GameObject đang active để xử lý
		if (group->objects[i]->IsActive())
		{
			this->AddGameObject(group->objects[i]);
		}
	}
}

void GroupObject::GetCollisionObjectQTree(int root_num)
{
	// Xóa trước khi thêm cái khác
	this->objects.clear();
	this->size = 0;

	// Gửi những game objects va chạm với viewport vào trong GroupObject này
	switch (root_num)
	{
	case 1:
		manager->rootQNode1->SendObjectsToGroup(this);
		break;
	case 2:
		manager->rootQNode2->SendObjectsToGroup(this);
		break;
	}
	
}

void GroupObject::GetCollisionObjects()
{
	// Enemy cần để xét va chạm
	//this->GetGroupObjectFrom(manager->enemyGroup);
}

void GroupObject::SetEnemyActive(ENEMY_TYPE enemy_type, float posX, float posY)
{
	for (int i = 0; i < size; i++)
	{
		Enemy * enemy = (Enemy*)objects[i];
		// Nếu unactive mới lấy
		if (enemy->GetEnemyType() == enemy_type && enemy->IsActive() == false)
		{
			enemy->Init(posX, posY);
		}
	}
}

Enemy * GroupObject::GetUnActiveEnemy(GroupObject * enemygroup, ENEMY_TYPE enemy_type)
{
	for (int i = 0; i < enemygroup->size; i++)
	{
		// Nếu unactive mới lấy
		if (enemygroup->objects[i]->GetType() == enemy_type && enemygroup->objects[i]->IsActive() == false)
		{
			return (Enemy*)enemygroup->objects[i];
		}
	}
	// Nếu không có thì thôi
	return NULL;
}

Item * GroupObject::GetUnActiveItem(GroupObject * itemgroup, ITEM_TYPE item_type)
{
	for (int i = 0; i < itemgroup->size; i++)
	{
		// Nếu unactive mới lấy
		if (itemgroup->objects[i]->GetType() == item_type && itemgroup->objects[i]->IsActive() == false)
		{
			return (Item*)itemgroup->objects[i];
		}
	}
	//Nếu không có thì thôi
	return NULL;
}
